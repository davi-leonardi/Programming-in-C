#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include <ctype.h>
#include "contactHelpers.h"
#include "contacts.h"

int main(void) 
{
	struct Contact contact = { { { '\0' } } };
	getNumbers(&contact);
	return 0;
}