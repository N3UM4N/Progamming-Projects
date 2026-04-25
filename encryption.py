character_array = [' ','!','"','#','$','%','&','(',')','*','+',',',
                   '-','.','/','0','1','2','3','4','5','6','7','8','9',
                   ':',';','<','=','>','?','@','A','B','C','D','E','F',
                   'G','H','I','J','K','L','M','N','O','P','Q','R','S',
                   'T','U','V','W','X','Y','Z','[','\\',']','^','_','`',
                   'a','b','c','d','e','f','g','h','i','j','k','l','m',
                   'n','o','p','q','r','s','t','u','v','w','x','y','z',
                   '{','|','}','~']


contin = True

while contin == True:
    newdata = open("pass.txt",'a')
    adddata = input("Enter new data or -99 to end: ")
    if adddata == "-99":
        contin = False
    else:
        count = 0
        encrypt = "" 
        while count < len(adddata):
            for i in range(0, len(character_array)):
                if adddata[count] == character_array[i]:
                    encrypt = encrypt + character_array[(i - 6) + 2]
            count = count + 1
        newdata.write(encrypt)
        newdata.write("\n")
        newdata.close()



readfile = open("pass.txt",'r')
items = readfile.readlines()

count = 0
outcount = 0 
dataarr = ["" for i in range(0,len(items))]
while count < len(items):
    data = items[count]
    iter = 0
    deciphered = ""
    while iter < len(data):
        for i in range(0, len(character_array)):
            if data[iter] == character_array[i]:
                deciphered = deciphered + character_array[(i - 2) + 6]
        iter = iter + 1
    new = ""
    for ii in range(0,len(deciphered)):
        new = new + deciphered[ii]
    dataarr[outcount] = new
    outcount = outcount + 1
    count = count + 1
readfile.close()

data_arr = [["" for i in range(0,4)] for i in range(0,(len(dataarr) // 4))]
readcount = 0

outer_count = 0
stop = False

removed_char = ['-','u','s','e','r',':','p','a','s','s']

while outer_count < len(data_arr) and stop == False:
    inner_count = 0
    while inner_count < len(data_arr[outer_count]):
        data_arr[outer_count][inner_count] = dataarr[readcount]
        if readcount == (len(dataarr) - 1):
            stop = True
        else:
            readcount = readcount + 1
        inner_count = inner_count + 1
    outer_count = outer_count + 1

outer_count = 0
data_to_find = input("Enter logins details to find:  ")
while outer_count < len(data_arr):
    if data_arr[outer_count][0] == str(data_to_find):
        print(data_arr[outer_count][2])
        print(data_arr[outer_count][3])
        outer_count = len(data_arr)
    outer_count = outer_count + 1