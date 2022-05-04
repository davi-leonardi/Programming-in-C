#pragma once

//Group member: Davi Leonardi
//ID: 154979199
//E-mai: dleonardi-mathey@myseneca.ca

//Group member: Ryo Aoyama
//ID: 166137190
//E-mail: raoyama@myseneca.ca

struct ProductInfo
{
	int stockAmount;
	int category;
	double price;
	char name[22];
};

struct StockRecord
{
	struct ProductInfo productInfo;
	int productId;
	double byWeight;
};

struct SalesRecord
{
	int saleProductId;
	double quantity;
};

#define MAX_ITEMS_IN_SALE 100

int readStockItems(struct StockRecord storeStocks[], int size, int size1);

void printStockReport(struct StockRecord storeStocks[], int row);

void centreText(int size, char symbol, char title[]);

int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord saleItems[]);

int getPurchase(struct SalesRecord saleItems[]);

int checkInvalid(struct SalesRecord saleItems[], int cancel);

int printSalesReport(struct StockRecord storeStocks[], struct SalesRecord* saleItems, int numSaleItems);

int findIndex(struct StockRecord* storeStocks, int salesId);

double getTax(const struct StockRecord* storeStocks, const double price);