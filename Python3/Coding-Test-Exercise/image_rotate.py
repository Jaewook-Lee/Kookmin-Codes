import sys
from copy import deepcopy


def print_image(_image: list, _size: int):
    for i in range(_size):
        for j in range(_size):
            print(_image[i][j], end='')
        print()


def rotate_image(_image: list, image_size: int, degree: int):
    if degree < 0:
        rotate_image(_image, image_size, 360 + degree)
    elif degree == 0:
        print_image(image, image_size)
    else:
        row_inc, col_inc = 0, 0
        if degree == 90:
            row_inc, col_inc = 0, image_size - 1
        elif degree == 180:
            row_inc = col_inc = image_size - 1
        else:
            row_inc, col_inc = image_size - 1, 0

        tmp_img = deepcopy(_image)
        for i in range(image_size):
            r, c = row_inc, col_inc
            for j in range(image_size):
                tmp_img[j + r][i + c] = _image[j][i]

                if degree == 90:
                    r, c = r - 1, c - 1
                elif degree == 180:
                    r -= 2
                else:
                    r, c = r - 1, c + 1

            if degree == 90:
                row_inc, col_inc = row_inc + 1, col_inc - 1
            elif degree == 180:
                col_inc -= 2
            else:
                row_inc, col_inc = row_inc - 1, col_inc - 1

        print_image(tmp_img, image_size)


if __name__ == "__main__":
    image = []

    test_cases = int(sys.stdin.readline())
    for _ in range(test_cases):
        size, rotate_degree = map(int, sys.stdin.readline().split())
        for i in range(size):
            row_info = list(sys.stdin.readline().strip())
            image.append(row_info)

        rotate_image(image, size, rotate_degree)
        image.clear()