import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 500, 300
FPS = 60

# Colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Dragon Jump Game")

# Load images
dragon_img = pygame.image.load("dragon.png")
dragon_img = pygame.transform.scale(dragon_img, (50, 50))

# Game variables
dragon_x = 50
dragon_y = HEIGHT - 100
dragon_velocity_y = 0
gravity = 1.5
jump = -20

# Main game loop
clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and dragon_y == HEIGHT - 100:
                dragon_velocity_y = jump

    # Update game logic
    dragon_velocity_y += gravity
    dragon_y += dragon_velocity_y

    # Keep dragon within the screen bounds
    if dragon_y > HEIGHT - 100:
        dragon_y = HEIGHT - 100
        dragon_velocity_y = 0

    # Draw background
    screen.fill(WHITE)

    # Draw dragon
    screen.blit(dragon_img, (dragon_x, dragon_y))

    # Update display
    pygame.display.flip()

    # Cap the frame rate
    clock.tick(FPS)

# Quit the game
pygame.quit()
sys.exit()
