typedef struct dig
{
	char data;
	struct dig *next;
}digit;
struct num
{
	int base;
	digit *digits;
	int length;
};
typedef struct num Number;
