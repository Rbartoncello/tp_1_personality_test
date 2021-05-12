#include <stdio.h>
#include <stdbool.h>

#define ANIME_TV_CHANNEL 'A'
#define POP_MUSIC_TV_CHANNEL 'M'
#define CLEANING_TV_CHANNEL 'L'

#define BAMBOO_FOOD 'B'
#define FISH_FOOD 'P'
#define SEAL_FOOD 'F'

const int MIN_BUILDING_LEVEL = 1;
const int MAX_BUILDING_LEVEL = 18;

const int MIN_SCREAM_POWER = 1;
const int MAX_SCREAM_POWER = 18;


const int CLEANING_TV_CHANNEL_SCORE = 1;
const int ANIME_TV_CHANNEL_SCORE = 2;
const int POP_MUSIC_TV_CHANNEL_SCORE = 3;

const int SEAL_FOOD_SCORE = 3;
const int BAMBOO_FOOD_SCORE = 6;
const int FISH_FOOD_SCORE = 9;


const int MIN_POLAR_BEAR_SCORE = 5;
const int MAX_POLAR_BEAR_SCORE = 24;

const int MIN_PANDA_BEAR_SCORE = 25;
const int MAX_PANDA_BEAR_SCORE = 43;

const int MIN_GRIZZLY_BEAR_SCORE = 44;
const int MAX_GRIZZLY_BEAR_SCORE = 63;

const char POLAR_LETTER = 'I';
const char PANDA_LETTER = 'P';
const char GRIZZLY_LETTER = 'G';

/*
 * Pre: -
 * Post: Devolvera TRUE si el char ingresado para tv_channel es ANIME_TV_CHANNEL o POP_MUSIC_TV_CHANNEL o  CLEANING_TV_CHANNEL 
 *	o FALSE si no.
 */
bool is_tv_channel_letter_valid(char tv_channel_letter){
	return(tv_channel_letter == ANIME_TV_CHANNEL || tv_channel_letter == POP_MUSIC_TV_CHANNEL || tv_channel_letter == CLEANING_TV_CHANNEL);
}
/*
 * Pre: -
 * Post: Devolvera TRUE si el char ingresado para food_type es BAMBOO_FOOD o FISH_FOOD o  SEAL_FOOD 
 *	o FALSE si no.
 */
bool is_food_letter_valid(char food_letter){
	return(food_letter == BAMBOO_FOOD || food_letter == FISH_FOOD || food_letter == SEAL_FOOD);
}
/*
 * Pre: -
 * Post: Devolvera TRUE si el numero ingresado entre MIN_BUILDING_LEVEL y MAX_BUILDING_LEVEL o FALSE si no.
 */
bool is_building_number_valid(int building_number){
	return(building_number >= MIN_BUILDING_LEVEL && building_number <= MAX_BUILDING_LEVEL);
}
/*
 * Pre: -
 * Post: Devolvera TRUE si el numero ingresado entre MIN_SCREAM_POWER y MAX_SCREAM_POWER o FALSE si no.
 */
bool is_scream_score_valid(int scream_score){
	return(scream_score >= MIN_SCREAM_POWER && scream_score <= MAX_SCREAM_POWER);
}
/*
 * Pre: -
 * Post: Imprimira un mensaje al usuario para que ingrese el char que le corresponde a tv_channel
 */
void print_user_message_tv_channel_selection(char* tv_channel_seletion){
	printf("OMG!! es el fin del mundo y tenes que elegir una categoria de Netflix para ver de por vida cual elejis:\n1. Anime (%c)\n2. Musica Pop (%c)\n3. Limpieza (%c)\n", ANIME_TV_CHANNEL, POP_MUSIC_TV_CHANNEL, CLEANING_TV_CHANNEL);
	scanf("%c", tv_channel_seletion);

	while (!is_tv_channel_letter_valid(*tv_channel_seletion)){
		
		printf("ERROR!!!.\nNo quiero ser malo pero el dato incresado NO es valido. Ponete la 10 y ingresa:\n1. Anime (%c)\n2. Musica Pop (%c)\n3. Limpieza (%c)\n", ANIME_TV_CHANNEL, POP_MUSIC_TV_CHANNEL, CLEANING_TV_CHANNEL);
		scanf(" %c", tv_channel_seletion);
	}
}
/*
 * Pre: -
 * Post: Imprimira un mensaje al usuario para que ingrese el char que le corresponde a food_type
 */
void print_user_message_food_type_selection(char* food_type_selection){
	printf("Te toca guardar la comida, por este temita que es el fin del mundo viste, que vas a guardar:\n1. Bambú (%c)\n2. Pescado (%c)\n3. Focas (%c)\n", BAMBOO_FOOD, FISH_FOOD, SEAL_FOOD);
	scanf(" %c", food_type_selection);

	while (!is_food_letter_valid(*food_type_selection)){
		
		printf("ERROR!!!.\nNo quiero ser malo pero el dato incresado NO es valido. Ponete la 10 y ingresa:\n1. Bambú (%c)\n2. Pescado (%c)\n3. Focas (%c)\n", BAMBOO_FOOD, FISH_FOOD, SEAL_FOOD);
		scanf(" %c", food_type_selection);
	}
}
/*
 * Pre: -
 * Post: Imprimira un mensaje al usuario para que ingrese el numero que le corresponde a building_number
 */
void print_user_message_building_level_selection(int* building_number_selection){
	printf("Encontras la olla con el oro del duende maldito y te compras una torre con tus dos hermanos de %i pisos.\n¿En que piso te gustaría vivir?: ", MAX_BUILDING_LEVEL);
	scanf("%i", building_number_selection);

	while (!is_building_number_valid(*building_number_selection)){
		
		printf("ERROR!!!.\nNo quiero ser malo pero el dato incresado NO es valido. Ponete la 10 y ingresa un numero entre %i y %i: ", MIN_BUILDING_LEVEL, MAX_BUILDING_LEVEL);
		scanf("%i", building_number_selection);
	}
}
/*
 * Pre: -
 * Post: Imprimira un mensaje al usuario para que ingrese el numero que le corresponde a scream_power
 */
void print_user_message_scream_power_selection(int* scream_power_selection){
	printf("¡Oh, el duende maldito se entero que le robaste su oro y viene por ti!\n¿Que tan fuerte gritas del %i al %i? Siendo %i no gritar y %i desgarrarse la garganta: ", MIN_SCREAM_POWER, MAX_SCREAM_POWER, MIN_SCREAM_POWER, MAX_SCREAM_POWER);
	scanf("%i", scream_power_selection);

	while (!is_scream_score_valid(*scream_power_selection)){
		
		printf("ERROR!!!.\nNo quiero ser malo pero el dato incresado NO es valido. Ponete la 10 y ingresa un numero entre %i y %i: ", MIN_SCREAM_POWER, MAX_SCREAM_POWER);
		scanf("%i", scream_power_selection);
	}
}
/*
 * Pre: Necesito tener el char correspondiente a tv_channel, el cual fue ingresado por el usuario
 * Post: Devolvera el valor numero que corresponde a tv_channel
 */
int tv_channel_score(char tv_channel_letter){

	int score = 0;

	switch(tv_channel_letter){
		case ANIME_TV_CHANNEL:
		score = ANIME_TV_CHANNEL_SCORE;
		break;
		case POP_MUSIC_TV_CHANNEL:
		score = POP_MUSIC_TV_CHANNEL_SCORE;
		break; 
		case CLEANING_TV_CHANNEL:
		score = CLEANING_TV_CHANNEL_SCORE;
		break;
	}

	return score;
}
/*
 * Pre: Necesito tener el char correspondiente a food_type, el cual fue ingresado por el usuario
 * Post: Devolvera el valor numero que corresponde a food_type
 */
int food_type_score(char food_letter){

	int score = 0;

	switch(food_letter){
		case BAMBOO_FOOD:
		score = BAMBOO_FOOD_SCORE;
		break;
		case FISH_FOOD:
		score = FISH_FOOD_SCORE;
		break;
		case SEAL_FOOD:
		score = SEAL_FOOD_SCORE;
		break;
	}

	return score;
}
/*
 * Pre: Necesito tener todos los datos solicitados de forma numerica
 * Post: Devolvera el calculo del total de todos los elememtos solicitados
 */
int total_score_calculation(int tv_channel_score, int food_type_score, int building_number_score, int scream_score){
		return (tv_channel_score * food_type_score) + building_number_score + scream_score;

}
/*
 * Pre: -
 * Post: Devolvera un mensaje al usuario dependiendo de un valor
 */
void print_bear_type(int score){

	if (score >= MIN_POLAR_BEAR_SCORE && score <= MAX_POLAR_BEAR_SCORE){
		printf("- Polar (%c) -\f 1. Callado, reacciona rápido, habla en tercera persona, demuestra pobremente sus emociones, responsable y maduro, valiente.\n 2. Le encanta la limpieza ya que la mayor parte de su tiempo pasa haciendo eso, y la cocina como podemos ver casi siempre.\n 3. Sabe artes marciales, yoga, bailar, patinar sobre hielo y tejer.\n 4. No puede controlar la cafeína.\n 5. Es el único personaje capaz de guardar objetos dentro de su brazo, por ejemplo, una barra de chocolate.\n 6. Le asustan los pepinos.\n", POLAR_LETTER);
	} else if (score >= MIN_PANDA_BEAR_SCORE && score <= MAX_PANDA_BEAR_SCORE){
		printf("- Panda (%c) -\f 1. Inseguro, sensible, se enamora rapido, tierno, vegetariano.\n 2. El celular es su alma en forma rectangular.\n 3. Usa lentes de contacto.\n 4. Tiene una almohada de Miki-Chan.\n 5. Le gusta ir de compras.\n 6. Le gusta el anime y las telenovelas.\n", PANDA_LETTER);
	} else if (score >= MIN_GRIZZLY_BEAR_SCORE && score <= MAX_GRIZZLY_BEAR_SCORE){
		printf("- Pardo (%c) -\f 1. Familiarizado con el área forestal.\n 2. Líder, hiperactivo, ruidoso, charlatan, alegre, optimista, extrovertido, quien hace los planes, glotón, sociable, disfruta de la atención, celoso, ingenuo.\n 3. Hace todo lo posible para hacer lo correcto.\n 4. De vez en cuando intentará hacerse famoso en Internet.\n 5. Amor por el cine. Le gustan las películas de acción.\n 6. Le gusta la cultura pop.\n", GRIZZLY_LETTER);
	}
}

int main (){

	char tv_channel, food_type;
	int building_number = 0, scream_power = 0;

	print_user_message_tv_channel_selection(&tv_channel);
	print_user_message_food_type_selection(&food_type);
	print_user_message_building_level_selection(&building_number);
	print_user_message_scream_power_selection(&scream_power);
	
	print_bear_type(total_score_calculation(tv_channel_score(tv_channel), food_type_score(food_type), building_number, scream_power));
	

	return 0;
}
