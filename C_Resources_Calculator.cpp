#include <iostream>
#include <string>

#define SIZE_OF_NAME_ARRAY 50
#define SIZE_OF_INFORMATION_ARRAY 500
#define SIZE_OF_DESCRIPTION_ARRAY 100

#define FIRST_LEVEL 1
#define MAX_LEVEL 90
#define ARTIFACT_MAX_LEVEL 20
#define ABILITY_MAX_LEVEL 10
#define RESOURCES_FOR_LEVELING_UP_WEAPON 10
#define RESOURCED_FOR_LEVELING_UP_ARTIFACT 15
#define RESOURCED_FOR_LEVELING_UP_ABILITY 3
#define RESOURCED_FOR_LEVELING_UP_CHARACTER 5

typedef struct Weapon {
    char name[SIZE_OF_NAME_ARRAY];
    int level;
    int damage;

    void GetInformation()
    {
        printf_s("%s %d Lvl. deals %d damage.", name, level, damage);
    }

    int CalculateResourcesForLevelingUp()
    {
        return RESOURCES_FOR_LEVELING_UP_WEAPON * (MAX_LEVEL - level);
    }
};

typedef struct Artifact {
    char name[SIZE_OF_NAME_ARRAY];
    int level;
    char description[SIZE_OF_DESCRIPTION_ARRAY];

    void GetInformation()
    {
        printf_s("%s %d Lvl. %s.", name, level, description);
    }

    int CalculateResourcesForLevelingUp()
    {
        return RESOURCED_FOR_LEVELING_UP_ARTIFACT * (ARTIFACT_MAX_LEVEL - level);
    }
};

typedef struct Ability {
    char name[SIZE_OF_NAME_ARRAY];
    int level;
    int damage;
    int cooldownInSeconds;

    void GetInformation()
    {
        printf_s("%s %d Lvl. deals %d per %d seconds.", name, level, damage, cooldownInSeconds);
    }

    int CalculateResourcesForLevelingUp()
    {
        return RESOURCED_FOR_LEVELING_UP_ABILITY * (ARTIFACT_MAX_LEVEL - level);
    }
};

typedef struct Character {
    char name[SIZE_OF_NAME_ARRAY];
    int level;
    Weapon weapon;
    Artifact artifact;
    Ability ability;

    void GetInformation()
    {
        printf_s("%s %d Lvl. holdes %s. ", name, level, weapon.name);
        weapon.GetInformation();
        printf_s(" %s holdes %s. ", name, artifact.name);
        artifact.GetInformation();
        printf_s(" %s has %s. ", name, ability.name);
        ability.GetInformation();
        printf_s("\n");
    }

    int CalculateResourcesForLevelingUp()
    {
        return RESOURCED_FOR_LEVELING_UP_CHARACTER * (MAX_LEVEL - level);
    }
};

typedef struct ResourcesCalculator {
    void CalculateResources(Character character)
    {
        printf_s("You need %d Wanderer's Advice, %d Enhancement Ores, %d Sanctifying Unctions and %d Teachings of Freedom.\n",
            character.CalculateResourcesForLevelingUp(), character.weapon.CalculateResourcesForLevelingUp(),
            character.artifact.CalculateResourcesForLevelingUp(), character.ability.CalculateResourcesForLevelingUp());
    }
};

int main()
{
    Character* someCharacter;

    Character wriothesley = { "Wriothesley", 1, {"The Widsith", 70, 413}, {"Marechaussee Hunter", 13, "Normal and Charged Attack DMG +15%."}, {"Icefang Rush", 1, 70, 16} };
    someCharacter = &wriothesley;
    someCharacter->GetInformation();

    ResourcesCalculator calc;
    calc.CalculateResources(wriothesley);

}