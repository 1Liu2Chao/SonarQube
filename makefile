CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = sonarqube_test
SOURCES = sonarqube_test.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
