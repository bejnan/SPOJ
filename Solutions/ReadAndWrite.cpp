#include<cstdio>

const int buf_size = 50000;
const int char_size = 1;

using namespace std;

class writer {
public:
	char buf[buf_size];
	int head;
	writer() :
			head(0) {
	}
	inline void flow() {
		fwrite(buf, char_size, head, stdout);
		head = 0;
	}
	inline void put_int(int l) {
		int i = 0;
		if (buf_size - head < 10)
			this->flow();
		if (l > 999999) {
			i = head + 6;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 8;
			buf[head - 1] = ' ';
		} else if (l > 99999) {
			i = head + 5;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 7;
			buf[head - 1] = ' ';
		} else if (l > 9999) {
			i = head + 4;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 6;
			buf[head - 1] = ' ';
		} else if (l > 999) {
			i = head + 3;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 5;
			buf[head - 1] = ' ';
		} else if (l > 99) {
			i = head + 2;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 4;
			buf[head - 1] = ' ';
		} else if (l > 9) {
			i = head + 1;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 3;
			buf[head - 1] = ' ';
		} else {
			buf[head++] = l + '0';
			buf[head++] = ' ';
		}
	}
	inline void endline() {
		buf[head++] = '\n';
	}
};
class reader {
public:
	char buf2[buf_size];
	int head, tail;

	reader() :
			head(0), tail(0) {
	}

	inline void get_chars() {
		int count = fread(buf2, char_size, buf_size, stdin);
		head = 0;
		tail = count;
	}
	inline void read_int(int &x) {
		char z;
		x = 0;
		do {
			if (head == tail)
				get_chars();
			z = buf2[head++];
		} while (z < '0');
		if (tail - head < 9)
			do {
				x = x * 10 + (z - '0');
				if (head == tail)
					get_chars();
				z = buf2[head++];
			} while (z >= '0');
		else {
			do {
				x = x * 10 + (z - '0');
				z = buf2[head++];
			} while (z >= '0');
		}
	}
};
