from pcbmodezero import PCB

BOARD_NAME = 'blinky'
(BOARD_WIDTH, BOARD_HEIGHT) = (25.0, 25.0)
BOARD_OUTLINE = PCB.create_square_shape(BOARD_WIDTH, BOARD_HEIGHT)

pcb = PCB(board_name = BOARD_NAME)

pcb.add_documentation('manufacturing', [BOARD_WIDTH / 2 + 10, -BOARD_HEIGHT / 2 + 8], "Manufacturing:...")
pcb.add_documentation('board_details', [BOARD_WIDTH / 2 + 10, -BOARD_HEIGHT / 2 + 6], "Board details: ...")
pcb.add_documentation('pcbmode', [0, -BOARD_HEIGHT / 2 - 5], "Designed with PCBmodE", font_size ="1.2", line_height ="1.2")
pcb.drill_index.location = [BOARD_WIDTH/ 2 + 10, -BOARD_HEIGHT / 2 - 5]

pcb.add_component('pin-header', 'J1', [0,  BOARD_HEIGHT / 2 - 2])
pcb.add_component('555', 'IC1', [0,  0], rotate = 90)


pcb.add_component('cap_elec_4mm_th', 'C1', [-2.5, -8.5], rotate = 90)

pcb.add_component('resistor-th', 'R1', [9, 0], rotate = 90)
pcb.add_component('resistor-th', 'R2', [6, -9])

pcb.add_component('led-3mm', 'LED1', [-BOARD_WIDTH / 2 + 4,  -BOARD_HEIGHT / 2 + 4], rotate = 45)
pcb.add_component('resistor-th', 'R3', [-BOARD_WIDTH / 2 + 3.5,  3], rotate = 90)

pcb.add_component('cercap', 'C2', [5.5,  BOARD_HEIGHT / 2 - 4], rotate = 45)

pcb.add_outline_path(BOARD_OUTLINE , width = BOARD_WIDTH, height = BOARD_HEIGHT)

pcb.save()
