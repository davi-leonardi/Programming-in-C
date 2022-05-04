#define _CRT_SECURE_NO_WARNINGS 

#define MAX_STOCK_ENTRIES 100 

#include <stdio.h> 
#include <string.h>
#include "stock.h" 

//Group member: Davi Leonardi
//ID: 154979199
//E-mai: dleonardi-mathey@myseneca.ca

//Group member: Ryo Aoyama
//ID: 166137190
//E-mail: raoyama@myseneca.ca

void displayStock(struct StockRecord* stockrecord, int row, int id)
{

    char array[7][16] = { "produce", "bakery", "meat","dairy", "baking", "house ware", "miscellaneous" };

    printf("%d%30s%20s%10.2lf%10d\n", stockrecord->productId, stockrecord->productInfo.name, array[stockrecord->productInfo.category - 1], stockrecord->productInfo.price, stockrecord->productInfo.stockAmount);

}



int readStockItems(struct StockRecord storeStock[], int size, int size1)
{

    int i;

    int number = 0;

    int count = 0;

    for (i = 0; i < size; i++)
    {
        scanf("%d%*c", &storeStock[i].productInfo.stockAmount);

        if (storeStock[i].productInfo.stockAmount > 0)
        {

            storeStock[i].productId = i + 1;

            do
            {

                scanf("%d%*c", &storeStock[i].productInfo.category);

                scanf("%lf%*c", &storeStock[i].productInfo.price);

                do
                {

                    scanf("%lf%*c", &storeStock[i].byWeight);

                    scanf("%19[^\n]%*[^\n]", &storeStock[i].productInfo.name);

                    getchar();


                    if (storeStock[i].productInfo.category < 1 || storeStock[i].productInfo.category > 7)
                    {
                        printf("Invalid Category - Enter a number between 1 and 7: ");
                    }

                    if (storeStock[i].byWeight != 0 && storeStock[i].byWeight != 1)
                    {
                        printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
                    }

                } while (storeStock[i].byWeight != 0 && storeStock[i].byWeight != 1);

            } while (storeStock[i].productInfo.category < 1 || storeStock[i].productInfo.category > 7);

        }


        if (storeStock[i].productInfo.stockAmount == 0)
        {
            i = size;
        }

        number++;

    }

    number = number - 1;

    return number;

}



void printStockReport(struct StockRecord storeStock[], int row)
{
    int i;

    printf("ID%29s%20s%10s%10s\n", "Product", "Category", "Price", "Quantity");

    for (i = 0; i < row; i++)
    {
        displayStock(&storeStock[i], row, i);
    }

}


void centreText(int size, char symbol, char title[])
{
    int i;
    int stringSize = 0;

    if (title != '\0')
    {
        
        stringSize = strlen(title);
        size -= stringSize;

        for (i = 0; i < (size / 2); i++)
        {
            printf("%c", symbol);
        }

        printf("%s", title);

        for (i = 0; i <= (size / 2); i++)
        {
            printf("%c", symbol);
        }
    }
    else 
    {
        for (i = 0; i < size; i++)
        {
            printf("%c", symbol);
        }
    }
}


int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord saleItems[])
{
    int numSalesItems = 0;
    int cancel = 1;
    int invalidChecker = 0;
    int i = -1;

    while (cancel == 1)
    {
        i++;
        printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
        scanf("%d%*c", &saleItems[i].saleProductId);
        cancel = getPurchase(&saleItems[i]);

        invalidChecker = checkInvalid(&saleItems[i], cancel);
        
        if (cancel != 0)
        {
            numSalesItems += 1;
        }
    }

    return numSalesItems;
}

int getPurchase(struct SalesRecord saleItems[])
{

    if (saleItems->saleProductId == 0)
    {
        return 0;
    }
    else
    {
        scanf("%lf", &saleItems->quantity);

        return 1;
    }
}

int checkInvalid(struct SalesRecord saleItems[], int cancel)
{

    int flag = 0;

    while (flag == 0 && cancel != 0)
    {

        while ((saleItems->saleProductId > 14 || saleItems->saleProductId < 0) && cancel != 0)
        {
            printf("Invalid Product - Enter a number between 0 and 14: ");
            scanf("%d%*c", &saleItems->saleProductId);
            cancel = getPurchase(saleItems);
        }

        while ((saleItems->quantity < 0.10 || saleItems->quantity > 100.00) && cancel != 0)
        {
            printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
            scanf("%d%*c", &saleItems->saleProductId);
            cancel = getPurchase(saleItems);
        }

        if (saleItems->saleProductId <= 14 && saleItems->saleProductId > 0)
        {
            flag = 1;
        }
    }
}

int printSalesReport(struct StockRecord storeStock[], struct SalesRecord* saleItems, int numSaleItems)
{
    
    printf("\n");

    centreText(70, '*', " Seneca Groceries ");
    printf("\n");
    centreText(70, '=', "");

    printf("\n");
    
    int id = 0, index = 0;
    double quantity = 0.00, unitPrice = 0.00, price = 0.00, purchaseTotal = 0.00, total = 0.00, tax = 0.00, totalTax = 0.00;
    int i;
  
    for (i = 0; i < numSaleItems; i++)
    {
        id = saleItems[i].saleProductId;

        quantity = saleItems[i].quantity;

        index = findIndex(storeStock, id);

        unitPrice = storeStock[index].productInfo.price;

        if ((int)quantity < storeStock[index].productInfo.stockAmount)
        {
            price = (unitPrice * quantity);
        }
        else
        {
            price = (double)(unitPrice * storeStock[index].productInfo.stockAmount);
        }

        purchaseTotal += price;

        tax = getTax(&storeStock[index], price);

        totalTax += tax;

        total = purchaseTotal + totalTax;
      
        printf("%35s%17.2lf%19.2lf\n", storeStock[index].productInfo.name, unitPrice, price);

        if ((int)saleItems[index].quantity <= storeStock[index].productInfo.stockAmount)
        {
            storeStock[index].productInfo.stockAmount -= (int)saleItems[index].quantity;
        }     

    }  

    printf("Purchase Total%57.2lf\n", purchaseTotal);
    printf("Tax%68.2lf\n", totalTax);
    printf("Total%66.2lf\n", total);
    printf("Thank you for shopping at Seneca!\n\n");

    return purchaseTotal;
}

int findIndex(struct StockRecord* storeStock, int salesId)
{
    int i, index = 0;
       
    for (i = 0; i < MAX_STOCK_ENTRIES; i++)
    {
        if (storeStock[i].productId == salesId)
        {
            index = i;
            return index;
        }
    }
}

double getTax(const struct StockRecord* storeStock, const double price)
{
    double tax = 0.00;

    if (storeStock->productInfo.category == 6 || storeStock->productInfo.category == 7)
    {        
        tax = (price * 0.13);
    }
    
    return tax;
}