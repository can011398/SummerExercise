import pygame

# 初始化
pygame.init()
# 设置窗口大小
screen = pygame.display.set_mode((640, 480))
# 设置窗口标题
pygame.display.set_caption("Hello Pygame")  

running = True
# 事件循环
while running:
    # 检测事件
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    # 填充屏幕
    screen.fill((255, 255, 255))  # Fill the screen with black
    # 绘制圆圈
    pygame.draw.circle(screen, (255, 0, 0), (320, 240), 50)  # Draw a red circle
    # 更新缓存
    pygame.display.flip()  # Update the display
# 退出程序
pygame.quit()