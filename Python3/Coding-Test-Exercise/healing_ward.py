import sys


def time_to_fill(map_size: int, _row: int, _col: int, shape: str):
    if shape == "square":
        times = [_row, map_size - 1 - _row, _col, map_size - 1 - _col]
    else:
        times = [_row + _col, (map_size - 1 - _row) + _col,
                 _row + (map_size - 1 - _col), 2 * (map_size - 1) - _row - _col]

    times.sort()
    return times[-1]


def show_map_status(_map: list, _size: int, _time: int, _dead_pos: list, _ward_pos: list):
    max_dead_fill_t, body_cnt = 0, len(_dead_pos)
    for i in range(body_cnt):
        dead_row, dead_col = _dead_pos[i]
        fill_all_t = time_to_fill(_size, dead_row, dead_col, "square")
        max_dead_fill_t = fill_all_t if fill_all_t > max_dead_fill_t else max_dead_fill_t

        step = _time if fill_all_t > _time else fill_all_t
        for a in range(1, step + 1):
            start_row = 0 if dead_row < a else dead_row - a
            end_row = _size - 1 if dead_row + a >= _size else dead_row + a
            for b in range(start_row, end_row + 1):
                start_col = 0 if dead_col < a else dead_col - a
                end_col = _size - 1 if dead_col + a >= _size else dead_col + a
                for c in range(start_col, end_col + 1):
                    _map[b][c] -= 1

            print(" ====== Dead Body %d Ver. After %d time ===== " % (i, a))
            for k in range(_size):
                for l in range(_size):
                    print(_map[k][l], end=' ')
                print()

    max_ward_fill_t, num_wards = 0, len(_ward_pos)
    for j in range(num_wards):
        ward_row, ward_col = _ward_pos[j]
        fill_all_t2 = time_to_fill(_size, ward_row, ward_col, "diamond")
        max_ward_fill_t = fill_all_t2 if fill_all_t2 > max_ward_fill_t else max_ward_fill_t

        step2 = _time if fill_all_t2 > _time else fill_all_t2
        for d in range(1, step2 + 1):
            for e in range(_size):
                for f in range(_size):
                    if abs(ward_row - e) + abs(ward_col - f) <= d:
                        _map[e][f] += 1

            print(" ====== Heal ward %d Ver. After %d time ===== " % (j, d))
            for k in range(_size):
                for l in range(_size):
                    print(_map[k][l], end=' ')
                print()

    if _time > (max_obj_fill_t := max(max_dead_fill_t, max_ward_fill_t)):
        _time -= max_obj_fill_t
        for g in range(_size):
            for h in range(_size):
                _map[g][h] += (num_wards - body_cnt) * _time

    print(" ====== Final Ver. After %d time ===== " % _time)
    for k in range(_size):
        for l in range(_size):
            print(_map[k][l], end=' ')
        print()


if __name__ == "__main__":
    test_case = int(sys.stdin.readline())
    for _ in range(test_case):
        size, time = map(int, sys.stdin.readline().split())
        dead_body_cnt, ward_cnt = map(int, sys.stdin.readline().split())
        world_map = [[0 for _ in range(size)] for _ in range(size)]

        dead_pos = []
        for _ in range(dead_body_cnt):
            dead_r, dead_c = map(int, sys.stdin.readline().split())
            dead_pos.append((dead_r, dead_c))

        ward_pos = []
        for _ in range(ward_cnt):
            ward_r, ward_c = map(int, sys.stdin.readline().split())
            ward_pos.append((ward_r, ward_c))

        show_map_status(world_map, size, time, dead_pos, ward_pos)
