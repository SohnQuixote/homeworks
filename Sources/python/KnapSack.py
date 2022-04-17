import random
def get_optimal_value(capacity, weights, values, names):
    size = len(weights)
    vpw = [(values[i] / weights[i], weights[i], names[i]) 
                                        for i in range(size)]
    densities = sorted(vpw, reverse = True)
    finalValue = 0
    for i, v in enumerate(densities):
        a = min(capacity, densities[i][1])
        finalValue += a * densities[i][0]
        print("가치가 ",densities[i][0], "인",densities[i][2], a, "gram is taken") 
        capacity -= a
    return finalValue
temp =0
values = []
weights = []
for i in range (0,10):
    values.insert(i, random.randint(30000,100000))
    #print(values[i])
    weights.insert(i,random.randint(5,30))
    #print(weights[i])
    temp += weights[i]
capacity = int(2/3 * temp)
print("가방크기 : " ,capacity)
names = ["주석", "백금", "은", "금" ,"루비" , "다이아" , "사파이어" ,"에메랄드" , "동" ,"진주"]
opt_value = get_optimal_value(capacity, weights, values, names)
print("Value of the knapsack is", opt_value)
