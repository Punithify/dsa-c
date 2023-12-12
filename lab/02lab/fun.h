struct ll{
	char name[20];
	int data;
	struct ll *link;
};

struct ll *newll();
void inbegin(struct ll *temp);
void display(struct ll *ptr);
int count(struct ll *temp);
void loop();
void inbetween(struct ll *temp,int pos);
void inend(struct ll *temp);
void del(struct ll *temp);
int searchid(int id);
struct ll *delbegin(struct ll *temp);
void delbetween(struct ll *temp,int pos);
void delend(struct ll *temp);
