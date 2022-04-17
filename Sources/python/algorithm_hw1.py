def coin_counting (won):
    if(won>= 500) :
        return coin_counting(won-500) +1
    if(won>=100) :
        return coin_counting(won-100) +1
    if(won>=50) :
        return coin_counting(won-50) +1
    if(won>=10) :
        return coin_counting(won-10) +1
    if(won>=1) :
        return coin_counting(won-1) +1
    if(won ==0 ):
        return 0

coin = int(input())
n = coin_counting(coin)
print(n)