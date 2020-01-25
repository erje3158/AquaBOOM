//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//   ________  ________  ___  ___  ________  ________  ________  ________  _____ ______      
//  |\   __  \|\   __  \|\  \|\  \|\   __  \|\   __  \|\   __  \|\   __  \|\   _ \  _   \    
//  \ \  \|\  \ \  \|\  \ \  \\\  \ \  \|\  \ \  \|\ /\ \  \|\  \ \  \|\  \ \  \\\__\ \  \   
//   \ \   __  \ \  \\\  \ \  \\\  \ \   __  \ \   __  \ \  \\\  \ \  \\\  \ \  \\|__| \  \  
//    \ \  \ \  \ \  \\\  \ \  \\\  \ \  \ \  \ \  \|\  \ \  \\\  \ \  \\\  \ \  \    \ \  \ 
//     \ \__\ \__\ \_____  \ \_______\ \__\ \__\ \_______\ \_______\ \_______\ \__\    \ \__\
//      \|__|\|__|\|___| \__\|_______|\|__|\|__|\|_______|\|_______|\|_______|\|__|     \|__|
//                       \|__|                                                                
//
// 1D Hydraulic Transient Solver
// 
// Created By Erik Jensen, Ph.D.
// August 7, 2019 - Version v0.1  
//
// Copyright © 2019 Erik Jensen
// All Rights Reserved
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "solver.h"

const double PI = 3.14159265358979323846;
const double g = 9.8;

int singlePhaseSolver::getNumberOfElements(){
	return numberOfElements;
}

int singlePhaseSolver::getOscillations(){
	return oscillations;
}

double singlePhaseSolver::getFlowRate(){
	return flowRate;
}

double singlePhaseSolver::getReservoirHeight(){
	return reservoirHeight;
}

double singlePhaseSolver::getValveClosingTime(){
	return valveClosingTime;
}

void singlePhaseSolver::setNumberOfElements(int numElem){
	numberOfElements = numElem;
}

void singlePhaseSolver::setOscillations(int osc){
	oscillations = osc;
}

void singlePhaseSolver::setFlowRate(double Q0){
	flowRate = Q0;
}

void singlePhaseSolver::setReservoirHeight(double H){
	reservoirHeight = H;
}

void singlePhaseSolver::setValveClosingTime(double t_v){
	valveClosingTime = t_v;
}

double singlePhaseSolver::getFlowVelocity(){
	return flowVelocity;
}

double singlePhaseSolver::getRenoldsNumber(){
	return renoldsNumber;
}

void singlePhaseSolver::setFlowVelocity(pipe* p){
	flowVelocity = flowRate / p->getArea();
}

void singlePhaseSolver::setRenoldsNumber(pipe* p, fluid* f){
	renoldsNumber = f->getDensity() * flowVelocity * p->getDiameter() / f->getViscosity();
}

double singlePhaseSolver::getTravelTime(){
	return travelTime;
}

double singlePhaseSolver::getTimeStep(){
	return timeStep;
}

double singlePhaseSolver::getTotalTime(){
	return totalTime;
}

void singlePhaseSolver::setTravelTime(pipe* p){
	travelTime = p->getLength() / p->getWaveSpeed();
}

void singlePhaseSolver::setTimeStep(){
	///TODO travelTime could be null (or uninitialized) - put in catch
	///TODO check integer division and recasting...
	timeStep = travelTime / numberOfElements;
}

void singlePhaseSolver::setTotalTime(){
	totalTime = 4 * oscillations * travelTime;
}

double singlePhaseSolver::getElementSize(){
	return elementSize;
}

int singlePhaseSolver::getNumberOfTimeSteps(){
	return numberOfTimeSteps;
}

int singlePhaseSolver::getNumberOfNodes(){
	return numberOfNodes;
}

void singlePhaseSolver::setElementSize(pipe* p){
	elementSize = p->getWaveSpeed() * timeStep;
}

void singlePhaseSolver::setNumberOfTimeSteps(){
	numberOfTimeSteps = (int) round(totalTime / timeStep);
}

void singlePhaseSolver::setNumberOfNodes(pipe* p){
	numberOfNodes = (int) round(p->getLength() / elementSize);
}

void singlePhaseSolver::initializeSolutionArrays(){
	//Creates flattened array
	flowRateSolution = new double[numberOfNodes * numberOfTimeSteps];
	headSolution = new double[numberOfNodes * numberOfTimeSteps];
}








