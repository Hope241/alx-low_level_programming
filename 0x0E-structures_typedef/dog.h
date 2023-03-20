#ifndef DOG_H_FILE
#define DOG_H_FILE

/**
 * struct dog - A structure definition of a dog.
 * @name: Dog name
 * @age: Dog age
 * @owner: The owner
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
