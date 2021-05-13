struct Hotel
{
	char city[20];
	char hotelName[20];
	char address[30];
	char roomClass[20];
	char amountOfFreeRooms[20];
	char roomCost[20];
};
void fillStruct(struct Hotel* hotels, int iter, const char* hotelsInfo, int stringSize);
void createStructArray(struct Hotel* hotels, int size, const char* fname);
int countStrings(const char* fname);
char* processRequest(char* str, char lastWord[100]);
bool reserveRoom(struct Hotel* hotels, int hotelAmount, int index);
void process();