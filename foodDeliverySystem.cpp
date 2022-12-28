#include <bits/stdc++.h>
using namespace std;

class Type
{

public:
    int typeId;
    string typeName;
    Type *next;

    Type(int id, string name)
    {
        typeId = id;
        typeName = name;
        next = NULL;
    }
};

class FoodType
{

public:
    Type *headT = NULL;
    Type *tempT = NULL;
    Type *currT = NULL;
    int arr[100000];

    int storeFoodType(string typeName)
    {

        int id = countSize();

        tempT = new Type(id + 1, typeName);

        if (headT == NULL)
        {

            headT = tempT;
        }
        else
        {

            currT = headT;

            while (currT->next != NULL)
            {

                currT = currT->next;
            }

            currT->next = tempT;
        }

        return tempT->typeId;
    }

    void displayFoodType()
    {

        currT = headT;
        cout << endl;
        while (currT != NULL)
        {

            cout << "Type ID:" << currT->typeId << " | Type Name: " << currT->typeName << endl;
            currT = currT->next;
        }
    }

    int countSize()
    {

        currT = headT;
        int c = 0;
        while (currT != NULL)
        {
            c++;
            currT = currT->next;
        }
        return c;
    }

    int *getTypeId()
    {
        currT = headT;
        int i = 0;
        while (currT != NULL)
        {

            arr[i] = currT->typeId;
            currT = currT->next;
            i++;
        }

        return arr;
    }

    void findFoodType(int typeId)
    {

        currT = headT;

        while (currT != NULL)
        {
            if (currT->typeId == typeId)
            {

                cout << "Type ID:" << currT->typeId << " | Type Name: " << currT->typeName << endl;
            }

            currT = currT->next;
        }
    }
};

class Item
{

public:
    int typeId;
    int itemId;
    string itemName;
    double price;
    Item *next;

    Item(int tId, int id, string name, double prc)
    {
        typeId = tId;
        itemId = id;
        itemName = name;
        price = prc;
        next = NULL;
    }
};

class FoodItem
{

public:
    Item *headI = NULL;
    Item *tempI = NULL;
    Item *currI = NULL;

    void storeFoodItem(int typeId, string itemName, double price)
    {

        int id = countSize();

        tempI = new Item(typeId, id + 1, itemName, price);

        if (headI == NULL)
        {

            headI = tempI;
        }
        else
        {

            currI = headI;

            while (currI->next != NULL)
            {

                currI = currI->next;
            }

            currI->next = tempI;
        }
    }

    double displayOrder(int itemId, int quantity)
    {

        currI = headI;
        int tSum = 0;

        while (currI != NULL)
        {
            if (itemId == currI->itemId)
            {

                cout << "Type ID: " << currI->typeId << " Item Id: " << currI->itemId << " Item Name: " << currI->itemName << " Price: " << currI->price << " Quantity: " << quantity << "Total: "<< (currI->price * quantity)<<endl;
                tSum = tSum + (currI->price * quantity);
            }
            currI = currI->next;
        }
        //cout<<"Order Total :"<<tSum<<endl;

        return tSum;

    }


    void displayFoodItem(int itemId, int quantity)
    {

        currI = headI;

        if (itemId == -1)
        {
            while (currI != NULL)
            {

                cout << "Type ID: " << currI->typeId << " Item Id: " << currI->itemId << " Item Name: " << currI->itemName << " Price: " << currI->price << " Quantity: " << quantity << endl;
                currI = currI->next;
            }
        }
        else
        {

            while (currI != NULL)
            {
                if (itemId == currI->itemId)
                {

                    cout << "Type ID: " << currI->typeId << " Item Id: " << currI->itemId << " Item Name: " << currI->itemName << " Price: " << currI->price << " Quantity: " << quantity <<endl;
                }
                currI = currI->next;
            }
        }
    }

    int countSize()
    {

        currI = headI;
        int c = 0;
        while (currI != NULL)
        {

            c++;
            currI = currI->next;
        }
        return c;
    }

    void displayItemByType(int typeId)
    {

        currI = headI;
        int c = 0;

        while (currI != NULL)
        {

            if (currI->typeId == typeId)
            {

                cout << "Item ID: " << currI->itemId << " | Item Name: " << currI->itemName << "| Item Price: "<< currI->price<<" BDT"<<endl;
            }

            currI = currI->next;
        }
    }
};

class OrderItem
{

public:
    int typeId;
    int itemId;
    int quantity;
    OrderItem *next;

    OrderItem(int typeId, int itemId, int qaunitity)
    {

        this->typeId = typeId;
        this->itemId = itemId;
        this->quantity = qaunitity;
        this->next = NULL;
    }
};

class OrderItemStack
{

public:
    OrderItem *top = NULL;
    OrderItem *temp = NULL;

    void push(int typeId, int itemId, int qauntity)
    {

        temp = new OrderItem(typeId, itemId, qauntity);
        if (top == NULL)
        {

            top = temp;
        }
        else
        {

            temp->next = top;
            top = temp;
        }
    }

    void display(FoodType ft, FoodItem fI)
    {

        if (top != NULL)
        {

            temp = top;
            while (temp != NULL)
            {
                // cout<<temp->typeId<<" "<<temp->itemId<<endl;
                ft.findFoodType(temp->typeId);
                fI.displayFoodItem(temp->itemId, temp->quantity);

                temp = temp->next;
            }
        }
    }

    double calculate(FoodType ft, FoodItem fI)
    {
        double orderSumPerCustomer = 0;
        if (top != NULL)
        {

            temp = top;
            while (temp != NULL)
            {
                // cout<<temp->typeId<<" "<<temp->itemId<<endl;
                ft.findFoodType(temp->typeId);
                orderSumPerCustomer = orderSumPerCustomer + fI.displayOrder(temp->itemId, temp->quantity);
                temp = temp->next;
            }
        }

        cout<<"Grand Total: "<<orderSumPerCustomer<<endl;

        return orderSumPerCustomer;
    }
};

class Order
{
public:
    int id;
    // int typeId;
    // int itemId;
    string customerName;
    string customerAddr;
    string customerMobile;
    Order *next;

    Order(int i, string cusName, string cusAddr, string cusMobile)
    {

        id = i;
        customerName = cusName;
        customerAddr = cusAddr;
        customerMobile = cusMobile;
        next = NULL;
    }
};

class FoodOrder
{

public:
    Order *headO = NULL;
    Order *tempO = NULL;
    Order *currO = NULL;

    void storeFoodOrder(string customerName, string customerAddr, string customerMobile)
    {

        int id = countSize();
        tempO = new Order(id + 1, customerName, customerAddr, customerMobile);

        if (headO == NULL)
        {

            headO = tempO;
        }
        else
        {

            currO = headO;
            while (currO->next != NULL)
            {

                currO = currO->next;
            }

            currO->next = tempO;
        }
    }

    int countSize()
    {

        currO = headO;
        int c = 0;
        while (currO != NULL)
        {

            c++;
            currO = currO->next;
        }
        return c;
    }

    void displayOrdersInfo(FoodType ft, FoodItem fI, OrderItemStack oI[], int customerNumber)
    {

        currO = headO;

        int i = 0;

        while (currO != NULL)
        {

            cout << endl;
            cout << "Order ID: " << currO->id << endl;
            cout << "Customer Info: " << endl;
            cout << "Customer Name: " << currO->customerName << " | Customer Address: " << currO->customerAddr << " | Customer Mobile: " << currO->customerMobile << endl;
            cout << "Item Info: " << endl;
            oI[i].display(ft, fI);
            i++;
            cout << endl;
            currO = currO->next;
        }
    }

    void generateOrderBill(FoodType ft, FoodItem fI, OrderItemStack oI[], int customerNumber)
    {

        currO = headO;

        int i = 0;

        double totalOrderSum = 0;
        while (currO != NULL)
        {

            cout << endl;
            cout << "Order ID: " << currO->id << endl;
            cout << "Customer Info: " << endl;
            cout << "Customer Name: " << currO->customerName << " | Customer Address: " << currO->customerAddr << " | Customer Mobile: " << currO->customerMobile << endl;
            cout << "Order Info: " << endl;
            totalOrderSum = totalOrderSum + oI[i].calculate(ft, fI);
            i++;
            cout << endl;
            currO = currO->next;
        }

        cout<<"Total Order Bill: "<<totalOrderSum<<endl;
    }
};

int main()
{

    FoodType ft;
    FoodItem fI;
    FoodOrder fO;
    OrderItemStack oI[10000];
    int customerNumber;

    while (1)
    {

        cout << "***************************" << endl;
        cout << "*Main Menu:               *" << endl;
        cout << "*1.Store Food In Reserve  *" << endl;
        cout << "*2.Take Customer Order    *" << endl;
        cout << "*3.Display Food Types     *" << endl;
        cout << "*4.Display Food Items     *" << endl;
        cout << "*5.Display All Orders     *" << endl;
        cout<<  "*6.Generate Bill          *" << endl;
        cout<<  "*7.Exit                   *" << endl;
        cout << "***************************" << endl;


        int op;
        cout << "Enter your option: ";
        cin >> op;

        if (op == 1)
        {
            cout << endl;
            cout << "Enter number of types: ";
            int numberOfTypes;
            cin >> numberOfTypes;

            for (int i = 0; i < numberOfTypes; i++)
            {
                cout << endl;
                cout << "Enter type " << i + 1 << " Name: ";
                string name;
                cin >> name;
                int typeId = ft.storeFoodType(name);
                cout << "Enter Number of Items: ";
                int numberOfItems;
                cin >> numberOfItems;
                cout << endl;

                for (int j = 0; j < numberOfItems; j++)
                {

                    string itemName;
                    cout << "Enter Item " << j + 1 << " Name: ";
                    cin >> itemName;
                    double price;
                    cout << "Enter Item " << j + 1 << " Price: ";
                    cin >> price;
                    fI.storeFoodItem(typeId, itemName, price);
                }
            }
        }
        else if (op == 2)
        {

            cout << endl;

            cout << "Enter number of customer: ";
            int n;
            cin >> n;
            customerNumber = n;

            for (int i = 0; i < n; i++)
            {

                cout << "******* Customer No. " << i + 1 << " Information Form *******" << endl;
                cout << endl;
                cout << "Enter Customer Name: ";
                string customerName;
                cin >> customerName;
                cout << "Enter Customer Address: ";
                string customerAddress;
                cin >> customerAddress;
                cout << "Enter Customer Mobile: ";
                string customerMobile;
                cin >> customerMobile;
                fO.storeFoodOrder(customerName, customerAddress, customerMobile);

                while (true)
                {

                    cout << "******* Select Type From Menu *******" << endl;

                    ft.displayFoodType();
                    cout << endl;
                    cout << "Select type Id: ";
                    int tId;
                    cin >> tId;

                    cout << endl;
                    cout << "******* Select Item From Menu *******" << endl;
                    cout << endl;
                    fI.displayItemByType(tId);
                    cout << endl;
                    cout << "Enter Item Id: ";
                    int iId;
                    cin >> iId;
                    cout << "Enter Quantity: ";
                    int quantity;
                    cin >> quantity;

                    oI[i].push(tId, iId, quantity);

                    cout << "Press n for next order, any other key to continue ordering...." << endl;
                    char c;
                    cin >> c;
                    if (c == 'n')
                    {

                        break;
                    }
                }
            }

            //            for(int i=0; i<n; i++)
            //            {
            //                cout<<"For customer No. "<<i+1<<endl;
            //                oI[i].display();
            //            }
        }
        else if (op == 3)
        {

            ft.displayFoodType();
        }
        else if (op == 4)
        {
            int *ptr;
            ptr = ft.getTypeId();
            cout << endl;
            for (int i = 0; i < ft.countSize(); i++)
            {
                // cout<<ptr[i]<<" ";
                ft.findFoodType(ptr[i]);
                cout << "*************" << endl;
                fI.displayItemByType(ptr[i]);
                cout << "*************" << endl;
            }

            // fI.displayFoodItem();
        }
        else if (op == 5)
        {

            fO.displayOrdersInfo(ft, fI, oI, customerNumber);

        }
        else if(op==6)
        {


            fO.generateOrderBill(ft, fI, oI, customerNumber);

        }
        else
            break;
    }
}

/*




*/
