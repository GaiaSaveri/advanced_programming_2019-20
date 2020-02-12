
def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise:
    '''
    ret = None
    l1 = list(string_var) #list from string
    l2 = l1[-1::-1] #list slicing
    return l1 == l2 

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    l1 = sorted(list(string_var)) #all repetitions are consecutive
    let = list({x for x in l1}) #unique values in l1, will be the key, used setcomps
    rep = list(0 for n in range(0, len(let))) #same len() of ler, all 0s, used listcomp
    for y in range(0,len(let)):
        r=0
        for x in l1[rep[y]:]:
            if(let[y] == x):
                r=r+1
                rep[y]+=1
            else :
                continue     
    return ({ k:v for k,v in zip(let,rep)}) #dictcomp + zip function

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
    ord = sorted(list_var) #sorted elements of list_var
    set = list({x for x in list_var}) #unique elements of list_var
    elem = 0 #most frequent element
    rep = 0 #number of repetition
    for i in set:
        r = 0
        for j in ord:
            if( i == j ):
                r=r+1
            else :
                if(r>rep) :
                    rep = r
                    elem = i
                    continue
                else:
                    continue
    return t = elem, rep #tuple packing

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    set = list({x for x in list_var})
    tup = [] #will be the list of tuples
    r = 0 #auxiliary var
    while(len(set)!= 0):
        tup.append(get_most_frequent(list_var)) #find most frequent
        set.remove(tup[r[0]]) #remove most frequent element
        r=r+1
    return dict(tup) #dict constructed from tuple


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    fact = 1
    for i in range(1, int_val+1): #stop is excluded
        fact = fact*i
    return fact


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    #assume int_val > 0
    for i in range(2, int_val):
        if(int_val%i==0):
            return False
        else: continue
    return True

        

