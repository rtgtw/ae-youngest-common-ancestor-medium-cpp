/*

youngest common ancestor

if they are equal to each other after bringing them on the same level
we can return that node since a node is its own ancestor


O(d) time , deepest decendant, O(1) time
*/

#include <iostream>	
#include <vector>


class AncestralTree {
public:
	char name;
	AncestralTree* ancestor;

	//Constructor
	AncestralTree(char name);

	/*void addAsAncestor(std::vector<AncestralTree*> decendants);*/

	AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor, AncestralTree* decendantOne, AncestralTree* decendantTwo);

	int getDepth(AncestralTree* decendant, AncestralTree* ancestor);

	AncestralTree* getYoungestAncestor(AncestralTree* lowerDecendant, AncestralTree* higherDecendant, int diff);
};

//Constructor
AncestralTree::AncestralTree(char name) {
	this->name = name;
	this->ancestor = NULL;
}


//Helper function, to get depth
int AncestralTree::getDepth(AncestralTree* decendant, AncestralTree* ancestor) {

	//Create a counter variable to count the depth
	int depth = 0;
	//Create a while loop to iterate until the decendant reaches the ancestor node(parent node)
	while (decendant != ancestor) {
		depth++;
		decendant = decendant->ancestor;
	}
	return depth;


}


//A second helper function to help get the common ancestor
AncestralTree* AncestralTree::getYoungestAncestor(AncestralTree* lowerDecendant, AncestralTree* higherDecendant, int diff) {
	//First we want to iterate the higher decendant to the same level as the lower one
	//We can use a for loop to get lowerDecendant on the same level as the higher one
	for (int i = 0; i < diff; i++) {
		lowerDecendant = lowerDecendant->ancestor;
	}

	//Now that they are on the same level we can compare and return the equal ancestor
	//iterates until they are equal to each other
	while (lowerDecendant != higherDecendant) {
		lowerDecendant = lowerDecendant->ancestor;
		higherDecendant = higherDecendant->ancestor;
	}

	//We can return either or
	return lowerDecendant;

}


//Solution
AncestralTree* AncestralTree::getYoungestCommonAncestor(AncestralTree* topAncestor, AncestralTree* decendantOne, AncestralTree* decendantTwo) {

	//The first thing we need to do is find the depth of decendant one and decendant two
	//We can create a helper function to get the depth
	int decendantOneDepth = getDepth(decendantOne,topAncestor);
	int decendantTwoDepth = getDepth(decendantTwo,topAncestor);

	//We need to figure out which decendant has the lower depth(deeper in the tree) 
	//and bring it up to the higher depth so they can be on the same level
	//This mean decendant one is deeper within the tree
	//We want to bring one towards two
	if (decendantOneDepth > decendantTwoDepth) {
		//We want to pass in decendant 1 and 2
		//along with the difference between one and two so we know
		//the depth decendant one has to travel
		return getYoungestAncestor(decendantOne, decendantTwo, decendantOneDepth - decendantTwoDepth);
	}
	else {
		return getYoungestAncestor(decendantTwo, decendantOne, decendantTwoDepth - decendantOneDepth);
	}
}