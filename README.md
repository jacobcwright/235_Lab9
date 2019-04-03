# 235_Lab9
Pokémon is a series of video games developed by Game Freak and published by Nintendo as part of the Pokémon media franchise. Review the "Pokémon battles" section of this wikipedia page if you are unfamiliar with the mechanics. We will be simplifying these mechanics down for the purpose of our lab. We will limit the number of types that a Pokémon can be to just one. Instead of Hit Points, we will use a system more closely related to a round of Rock-Paper-Scissors; whichever Pokémon uses the more effective move against the other wins.

Battles:
Battles will be much simpler than they are in the actual games. Each Pokémon has a single type (fire, water, rock). Each move (attack) is a single type.

Some move types are "super effective" or strong against Pokémon of certain types. For example, water is super effective against fire.
Some move types are "not very effective" or weak against Pokémon of certain types. For example, fire is not very effective against water.
Any move type that is neither strong nor weak against a Pokémon of a certain type is "regularly effective. You will read in tables of effectivities and ineffectivities. Any combination not found in either of the two tables is regarded as regularly effective. For example, rock is regularly effective against water because it has no advantage or disadvantage against it.
Move types can have any number of Pokémon types that they are strong or weak against.
In a single battle, two Pokémon are chosen and each Pokémon chooses one move to attack the other one with. Whichever Pokémon attacks with the more effective move wins the battle. If the two moves have equal effectiveness, then the battle ends in a tie.

Requirements:
Your Set class inherits from the SetInterface class (SetInterface.h).
Implements SetInterface.
No duplicates in Set container.
Set toString() returns ordered elements.
Implement a HashMap class that inherits from the HashMapInterface class (HashMapInterface.h).
Use a string hash function for accessing data as explained above with a HASH_CONSTANT equal to 3.
Use quadratic probing for collision resolution.
Dynamically allocate the array for your hash table.
Use DEFAULT_MAP_HASH_TABLE_SIZE as the initial hash table size.
Each Pokémon is stored in a HashMap<string,string>.
Each Move is stored in a HashMap<string,string>.
Each Efficiency is stored in a HashMap<string,Set<string>>.
Each Inefficiency is stored in a HashMap<string,Set<string>>.
Report who wins each battle.
The following summarizes the commands used in the Maps and Sets lab:

INPUT	OUTPUT
Set: <item> { <item>} 
Example input: 
Set: dog dog cat cat cat dog
Set: dog dog cat cat cat dog
  [cat dog]
Pokemon: <pokemon> <AType> 
Example input: 
Pokemon: Charmander fire
Pokemon: Squirtle water
Pokemon: Charmander fire
Pokemon: Squirtle water
Move: <move> <Move_Type> 
Example input: 
Move: flamethrower fire
Move: water_gun water
Move: flamethrower fire
Move: water_gun water
Effective: <attack> <PType>{ <PType>} 
Example input: 
Effective: fire grass ice bug steel
Effective: water ground rock fire
Effective: fire grass ice bug steel
Effective: water ground rock fire
Ineffective: <attack> <PType>{ <PType>} 
Example input: 
Ineffective: fire rock fire water
Ineffective: water water grass
Ineffective: fire rock fire water
Ineffective: water water grass
Pokemon 
Example input: 
Pokemon
Pokemon: 2/31
  [0:Squirtle->water]
  [30:Charmander->fire]
Moves 
Example input: 
Moves
Moves: 2/31
  [29:water_gun->water]
  [30:flamethrower->fire]
Effectivities 
Example input: 
Effectivities
Effectivities: 2/31
  [17:water->fire,ground,rock]
  [19:fire->bug,grass,ice,steel]
Ineffectivities 
Example input: 
Ineffectivities
Ineffectivities: 2/31
  [17:water->fire,ground,rock]
  [19:fire->bug,grass,ice,steel]
Battle: <P1> <A1> <P2> <A2> 
Example input: 
Battle: Charmander flamethrower Squirtle water_gun
Note: The auto-grader will be checking for the red lines only. 
Battle: Charmander flamethrower Squirtle water_gun
  Charmander (flamethrower) vs Squirtle (water_gun)
  Charmander is a fire type Pokemon.
  Squirtle is a water type Pokemon.
  flamethrower is a fire type move.
  water_gun is a water type move.
  flamethrower is super effective against [bug,grass,ice,steel] type Pokemon.
  flamethrower is ineffective against [fire,rock,water] type Pokemon.
  Charmander's flamethrower is ineffective against Squirtle
  water_gun is super effective against [fire,ground,rock] type Pokemon.
  water_gun is ineffective against [grass,water] type Pokemon.
  Squirtle's water_gun is super effective against Charmander
  In the battle between Charmander and Squirtle, Squirtle wins!
Steps to Success:
Step 1 - Design and implement a Set class that inherits from the SetInterface.h interface class.
This should be the easiest part of the lab. You have already created a BST class that the Set class could adapt. Adjust your BST toString() method to return elements in sorted (infix) order.
You could also use your LinkedList class, but you would need to eliminate duplicates and insert in sorted order.
Finally, you are allowed (for this lab only) to use the STL list container. Although not difficult, you would need to sort and remove duplicates on insertion and use a list iterator for the toString() functions.
Unit test the functionality of your Set implementation.
Step 2 - Design and implement a HashMap class that inherits from the HashMapInterface.h interface class.
Use string hashing as explained above for accessing map values. Use "long long" data type in calculating your string hash to avoid data type overflow. Return a "size_t" hash index.
Use quadratic probing for collision resolution.
You must use a dynamically allocated array for your hash table. In a normal map implementation you'd want to dynamically grow and shrink this "table," but for simplicity we will not require it (unless doing the bonus.)
Use DEFAULT_MAP_HASH_TABLE_SIZE as the initial hash table size.
Unit test the functionality of your HashMap implementation.
Step 3 - Populate pokemon, move, effectivities, and ineffectiveties maps.
Read in each Pokémon and store its type in a HashMap<string,string>.
Read in each move and store its type in a HashMap<string,string>.
Read in the type effectivities and ineffectivities and store them in HashMap<string,Set<string>>s.
Report who wins each battle.
Check to make sure you've correctly read in this information.
Step 4 - Implement the battle simulation.
For each battle, read in each Pokémon and the move that it is using.
Then check which move is the most effective against the other Pokémon and report the winner.
