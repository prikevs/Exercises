#!/usr/bin/env python2.7

def encrypt(data):
    ans = []
    for i in data:
        if i.isalpha():
            if chr(ord(i)+3).isalpha():
                ans.append(chr(ord(i)+3))
            else:
                ans.append(chr(ord(i)-23))
        else:
            ans.append(i)
    return "".join(ans)

def decrypt(data):
    ans = []
    for i in data:
        if i.isalpha():
            if chr(ord(i)-3).isalpha():
                ans.append(chr(ord(i)-3))
            else:
                ans.append(chr(ord(i)+23))
        else:
            ans.append(i)
    return "".join(ans)

def main():
    filename_in = raw_input("Please input name of the input file:")
    filename_out = raw_input("Please input name of the output file:")
    try:
        choice = int(raw_input("1.encrypt 2.decrypt\nYour choice:"))
    except ValueError, var:
        return
    f_in = open(filename_in ,"r")
    f_out = open(filename_out ,"w")

    data1 = f_in.read()

    if choice == 1:
        data2 = encrypt(data1)        
    elif choice == 2:
        data2 = decrypt(data1)
    else:
        data2 = ''

    f_out.write(data2)
    f_in.close()
    f_out.close()
     

if __name__ == '__main__':
    main()
