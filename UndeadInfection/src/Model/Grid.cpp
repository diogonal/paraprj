/*
 * Grid.cpp
 *
 *  Created on: 21/08/2014
 *      Author: achaves
 */

#include "Grid.h"
#include <iostream>
using namespace std;
Grid::Grid() {
}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

void Grid::initialize(int nPeople, int nZombies) {
	int numZombies = 0;
	int numHumans = 0;
	for (int i = 0; i < CELLROWSPERGRID; i++) {
		for (int j = 0; j < CELLCOLUMNSPERGRID; j++) {
			cells[i][j] = new Cell();
			cells[i][j]->setGrid(this);
			cells[i][j]->setCoordinates(i, j);

			//todo:change algorithm so it is random and with pop limits

			if (numHumans < DARWINPOPDENSITY && RandomGen::randomBool()) {
				cells[i][j]->setCurrentAgent(new Human(RandomGen::randomBool(), RandomGen::randomBool()));
				cells[i][j]->setCandidateAgent(nullptr);
				numHumans++;
			} else {
				if (numZombies < NUMBEROFZOMBIES && RandomGen::randomBool()) {
					cells[i][j]->setCurrentAgent(new Zombie());
					cells[i][j]->setCandidateAgent(nullptr);
					numZombies++;
				} else {
					cells[i][j]->setCurrentAgent(nullptr);
					cells[i][j]->setCandidateAgent(nullptr);
				}
			}
			//cout << "i:  "<<i << "j:  "<<j <<"Initialized with humans: "<< endl;
		}
	}
}

//Todo: check adjacencies and move
void Grid::addAgent(int x, int y, Agent* agent) {
	if (cells[x][y]->getCurrentAgent() == nullptr) {
		cells[x][y]->setCurrentAgent(agent);
		cells[x][y]->setCandidateAgent(nullptr);
	}
	//	cout << "added and agent at: "<<"x:  "<<x << "y:  "<<y<< endl;
}
void Grid::moveAgentCurrentToCurrent(int x, int y, Agent* agent, int xtoMove, int ytoMove) {
	if (cells[xtoMove][ytoMove]->getCurrentAgent() == nullptr) {
		cells[xtoMove][ytoMove]->setCurrentAgent(agent);
		cells[x][y]->setCurrentAgent(nullptr);
	}
	else {
		switch (RandomGen::getIntUniformRandomBetween(0, 8)) {
		{
			case 0:
			cells[x][y]->setCurrentAgent(nullptr);
			break;
			case 1:
			if (y - 1 >= 0) {
				this->moveAgentCurrentToCurrent(x, y, agent, x, y - 1); //Superior left cell
			}
			break;
			case 2:
			if (x - 1 >= 0)
				this->moveAgentCurrentToCurrent(x, y, agent, x - 1, y); //Superior center
			break;
			case 3:
			if (x - 1 >= 0 && y + 1 < CELLCOLUMNSPERGRID)
				this->moveAgentCurrentToCurrent(x, y, agent, x - 1, y + 1); //superior right
			break;
			case 4:
			if (y + 1 < CELLCOLUMNSPERGRID)
				this->moveAgentCurrentToCurrent(x, y, agent, x, y + 1); //Center center
			break;
			case 5:
			if (x + 1 < CELLROWSPERGRID && y + 1 < CELLCOLUMNSPERGRID)
				this->moveAgentCurrentToCurrent(x, y, agent, x + 1, y + 1); //Inferior right
			break;
			case 6:
			if (x + 1 < CELLROWSPERGRID)
				this->moveAgentCurrentToCurrent(x, y, agent, x + 1, y); //Inferior center
			break;
			case 7:
			if (x + 1 < CELLROWSPERGRID && y - 1 > 0)
				this->moveAgentCurrentToCurrent(x, y, agent, x + 1, y - 1); //Inferior left
			break;
			case 8:
			if (y - 1 > 0)
				this->moveAgentCurrentToCurrent(x, y, agent, x, y - 1); //Center left
			break;
		}
		}

	}
	//cout << "moved current2current agent from: "<<x << ","<<y << " to: " << xtoMove << "," << ytoMove << endl;
}
void Grid::moveAgentCurrentToCandidate(int x, int y, Agent* agent, int xtoMove, int ytoMove) {
	if (cells[xtoMove][ytoMove]->getCandidateAgent() == nullptr) {
		cells[xtoMove][ytoMove]->setCandidateAgent(agent);
		cells[x][y]->setCurrentAgent(nullptr);
	}
	else {
		switch (RandomGen::getIntUniformRandomBetween(0, 8)) {
		{
			case 0:
			cells[x][y]->setCurrentAgent(nullptr);
			break;
			case 1:
			if (y - 1 >= 0)
				this->moveAgentCurrentToCandidate(x, y, agent, x, y - 1); //Superior left cell
			break;
			case 2:
			if (x - 1 >= 0)
				this->moveAgentCurrentToCandidate(x, y, agent, x - 1, y); //Superior center
			break;
			case 3:
			if (x - 1 >= 0)
				this->moveAgentCurrentToCandidate(x, y, agent, x - 1, y + 1); //superior right
			break;
			case 4:
			if (y + 1 < CELLCOLUMNSPERGRID)
				this->moveAgentCurrentToCandidate(x, y, agent, x, y + 1); //Center center
			break;
			case 5:
			if (x + 1 < CELLROWSPERGRID && y + 1 < CELLCOLUMNSPERGRID)
				this->moveAgentCurrentToCandidate(x, y, agent, x + 1, y + 1); //Inferior right
			break;
			case 6:
			if (x + 1 < CELLROWSPERGRID)
				this->moveAgentCurrentToCandidate(x, y, agent, x + 1, y); //Inferior center
			break;
			case 7:
			if (x + 1 < CELLROWSPERGRID && y - 1 > 0)
				this->moveAgentCurrentToCandidate(x, y, agent, x + 1, y - 1); //Inferior left
			break;
			case 8:
			if (y - 1 > 0)
				this->moveAgentCurrentToCandidate(x, y, agent, x, y - 1); //Center left
			break;
		}
		}

	}

	//cout << "moved current2candidate agent from: "<<x << ","<<y << " to: " << xtoMove << "," << ytoMove << endl;
}
void Grid::moveAgentCandidateToCurrent(int x, int y, Agent* agent, int xtoMove, int ytoMove) {
	if (cells[xtoMove][ytoMove]->getCurrentAgent() == nullptr) {
		cells[xtoMove][ytoMove]->setCurrentAgent(agent);
		cells[x][y]->setCandidateAgent(nullptr);
	}
	else {
			switch (RandomGen::getIntUniformRandomBetween(0, 8)) {
			{
				case 0:
					cells[x][y]->setCurrentAgent(nullptr);
				break;
				case 1:
				if (y - 1 >= 0)
					this->moveAgentCandidateToCurrent(x, y, agent, x, y - 1); //Superior left cell
				break;
				case 2:
				if (x - 1 >= 0)
					this->moveAgentCandidateToCurrent(x, y, agent, x - 1, y); //Superior center
				break;
				case 3:
				if (x - 1 >= 0)
					this->moveAgentCandidateToCurrent(x, y, agent, x - 1, y + 1); //superior right
				break;
				case 4:
				if (y + 1 < CELLCOLUMNSPERGRID)
					this->moveAgentCandidateToCurrent(x, y, agent, x, y + 1); //Center center
				break;
				case 5:
				if (x + 1 < CELLROWSPERGRID && y + 1 < CELLCOLUMNSPERGRID)
					this->moveAgentCandidateToCurrent(x, y, agent, x + 1, y + 1); //Inferior right
				break;
				case 6:
				if (x + 1 < CELLROWSPERGRID)
					this->moveAgentCandidateToCurrent(x, y, agent, x + 1, y); //Inferior center
				break;
				case 7:
				if (x + 1 < CELLROWSPERGRID && y - 1 > 0)
					this->moveAgentCandidateToCurrent(x, y, agent, x + 1, y - 1); //Inferior left
				break;
				case 8:
				if (y - 1 > 0)
					this->moveAgentCandidateToCurrent(x, y, agent, x, y - 1); //Center left
				break;
			}
			}

		}
	//cout << "moved candidate2current agent from: "<<x << ","<<y << " to: " << xtoMove << "," << ytoMove << endl;
}
void Grid::removeAgent(int x, int y, Agent* agent) {
	cells[x][y]->setCurrentAgent(nullptr);
}
void Grid::calculateAgents(int &humans, int &zombies) {
	for (int i = 0; i < CELLROWSPERGRID; i++) {
		for (int j = 0; j < CELLCOLUMNSPERGRID; j++) {
			Agent* agent = cells[i][j]->getCurrentAgent();
			if (agent != nullptr) {
				AgentTypeEnum currentType = agent->getType();

				if (currentType == human)
					humans++;
				else
					zombies++;
			}
		}
	}
}
void Grid::step() {
	for (int i = 0; i < CELLROWSPERGRID; i++) {
		for (int j = 0; j < CELLCOLUMNSPERGRID; j++) {
#ifdef DEBUGGRID
			cout << "Moving cells in Grid " << i << "," << j << endl;
#endif
			cells[i][j]->move();
		}
	}
	for (int i = 0; i < CELLROWSPERGRID; i++) {
		for (int j = 0; j < CELLCOLUMNSPERGRID; j++) {
#ifdef DEBUGGRID
			cout << "Calling steps in Grid " << i << "," << j << endl;
#endif
			cells[i][j]->step();
		}
	}

}
