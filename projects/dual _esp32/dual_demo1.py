import pygame, serial, sys, random

# ---- serial setup ----
PORT = "/dev/ttyUSB0"      # change if 'ls /dev/ttyUSB*' shows a different number
BAUD = 115200
try:
    ser = serial.Serial(PORT, BAUD, timeout=0)
except Exception as e:
    print("Could not open serial:", e)
    print("-> Is the Arduino Serial Monitor closed? Is PORT correct?")
    sys.exit(1)

# ---- distance -> position mapping (tune to your hand range) ----
DIST_MIN, DIST_MAX = 5, 40   # cm; hand close = top, far = bottom

pygame.init()
W, H = 900, 560
screen = pygame.display.set_mode((W, H))
pygame.display.set_caption("Ultra Duel - Demo")
clock = pygame.time.Clock()
font = pygame.font.SysFont("consolas", 22)
big  = pygame.font.SysFont("consolas", 60, bold=True)

TEAL  = (46, 230, 193)
CORAL = (229, 97, 62)
WHITE = (235, 240, 245)
BG    = (12, 20, 30)

ship_y = H // 2
bullets = []          # each: [x, y]
enemies = []          # each: [x, y]
score = 0
lives = 5
last_fire = 0
spawn_timer = 0
prev_fire = 0
game_over = False

def read_serial():
    """Return (distance_cm or None, fire 0/1 or None) from the latest line."""
    dist, fire = None, None
    try:
        data = ser.read(200).decode(errors="ignore")
    except Exception:
        return None, None
    for line in data.split("\n"):
        line = line.strip()
        if line.startswith("D,"):
            parts = line.split(",")
            if len(parts) == 3:
                try:
                    dist = int(parts[1]); fire = int(parts[2])
                except ValueError:
                    pass
    return dist, fire

running = True
while running:
    now = pygame.time.get_ticks()
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            running = False
        if e.type == pygame.KEYDOWN and e.key == pygame.K_r and game_over:
            score, lives, enemies, bullets, game_over = 0, 5, [], [], False

    dist, fire = read_serial()

    if not game_over:
        # map hand distance -> ship vertical position
        if dist is not None:
            d = max(DIST_MIN, min(DIST_MAX, dist))
            ship_y = int((d - DIST_MIN) / (DIST_MAX - DIST_MIN) * (H - 60) + 30)

        # fire on the rising edge of FIRE (wave over IR)
        if fire == 1 and prev_fire == 0 and now - last_fire > 250:
            bullets.append([110, ship_y]); last_fire = now
        if fire is not None:
            prev_fire = fire

        # move bullets
        for b in bullets: b[0] += 12
        bullets = [b for b in bullets if b[0] < W]

        # spawn + move enemies (from the right)
        spawn_timer -= 1
        if spawn_timer <= 0:
            enemies.append([W - 30, random.randint(30, H - 30)])
            spawn_timer = random.randint(40, 80)
        for en in enemies: en[0] -= 3

        # bullet-enemy collisions
        for b in bullets[:]:
            for en in enemies[:]:
                if abs(b[0]-en[0]) < 22 and abs(b[1]-en[1]) < 22:
                    if b in bullets: bullets.remove(b)
                    if en in enemies: enemies.remove(en)
                    score += 1
                    break

        # enemy reaches your side -> lose a life
        for en in enemies[:]:
            if en[0] < 60:
                enemies.remove(en); lives -= 1
                if lives <= 0: game_over = True

    # ---- draw ----
    screen.fill(BG)
    # your ship (left, a triangle)
    pygame.draw.polygon(screen, TEAL, [(70, ship_y-18),(70, ship_y+18),(110, ship_y)])
    for b in bullets:
        pygame.draw.circle(screen, WHITE, (int(b[0]), int(b[1])), 5)
    for en in enemies:
        pygame.draw.circle(screen, CORAL, (int(en[0]), int(en[1])), 15)

    screen.blit(font.render(f"Score: {score}", True, WHITE), (16, 12))
    screen.blit(font.render(f"Lives: {lives}", True, WHITE), (16, 40))
    hud = "IR: waiting..." if dist is None else f"hand: {dist}cm"
    screen.blit(font.render(hud, True, (120,140,160)), (16, H-32))

    if game_over:
        t = big.render("GAME OVER", True, CORAL)
        screen.blit(t, (W//2 - t.get_width()//2, H//2 - 60))
        r = font.render("press R to restart", True, WHITE)
        screen.blit(r, (W//2 - r.get_width()//2, H//2 + 20))

    pygame.display.flip()
    clock.tick(60)

ser.close()
pygame.quit()
