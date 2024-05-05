size=5
client_list=[None]*size

def add_client_simple():
    client_id=int(input("Enter Client Id - "))
    client_name=input("Enter Client name - ")
    tele_no=int(input("Enter Telephone no - "))
    details=[client_id,client_name,tele_no]
    index=client_id % size

    for i in range(size):
        if(client_list[index]==None):
            client_list[index]=details
            print("Adding data - ",index," - ",details)
            break
        else:
            index=(index + 1)%size

def add_client_quadratic():
    client_id=int(input("Enter Client Id - "))
    client_name=input("Enter Client name - ")
    tele_no=int(input("Enter Telephone no - "))
    details=[client_id,client_name,tele_no]
    index=client_id % size
    ind=index
    for i in range(size):
        
        if(client_list[ind]==None):
            client_list[ind]=details
            print("Adding data - ",ind," - ",details)
            break
        else:
            ind=(index + i**2)%size

def search():
    client_id=int(input("Enter the id of client to be searched - "))
    index=(client_id)%size

    for i in range(size):
        if(client_list[index][0]==client_id):
            print(client_id," - Client found at position ",index)
            break
        else:
            index=(index+1)%size

def delete():
    client_id=int(input("Enter the id of client to be deleted - "))
    index=(client_id)%size

    for i in range(size):
        if(client_list[index][0]==client_id):
            client_list[index]=None
            print("Client Deleted")
            break
        else:
            index=(index+1)%size

def display():
    print("Client list - \n\n")
    for i in range(size):
        for j in range(3):
            if(client_list[i][j] != None):
                print(client_list[i][j])
                print("   ")
        print("\n")
    
add_client_simple()
add_client_simple()
add_client_simple()
add_client_quadratic()
add_client_quadratic()
display()
search()
delete()
display()











