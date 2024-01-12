def pair_sum(arr, n):
    start = 0
    end = len(arr) - 1
    while start<end:
        if(n>arr[start]+arr[end]):
            start+=1
        elif(n==arr[start]+arr[end]):
            print(arr[start], arr[end])
            break
        elif(n<arr[start]+arr[end]):
            end-=1

arr = [1,3,4,5,6,7,9,10,12,13]
n = int(input("Enter the sum: "))
pair_sum(arr, n)