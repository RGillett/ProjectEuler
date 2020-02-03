def is_permutation(first_number, second_number):
    return sorted(str(first_number)) == sorted(str(second_number))

for i in range (10000):
    count = 1
    number = i**3
    j = i+1
    while (len(str(j**3)) == len(str(number))):
        if (is_permutation(number, j**3)):
            count += 1
        j = j+1
    if (count >= 5):
        print(number)
        break