def powerful_digits_count():
    count = 0
    for x in range (1,22):
        for y in range(1,10):
            if (len(str(y**x)) == x):
                count += 1
    return count

print(powerful_digits_count())