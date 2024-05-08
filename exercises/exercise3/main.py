from math import factorial, comb

# Calculate the number of ways to form the teams
number_of_ways = comb(10, 4) * comb(6, 3) // factorial(2)
print(number_of_ways)
