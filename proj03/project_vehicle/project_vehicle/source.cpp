//Program Name: Vehicle Smorgasbord
//Programmer Name: Arthur Aigeltinger IV
//Description: Lots of validation
//Date Created: 11/26/18

#include "vehicle.h"
#include "boat.h"
#include "plane.h"
#include "landVehicle.h"
#include "car.h"
#include "truck.h"

#include <cctype>
#include <fstream>

//Function Prototypes
void vehicleMenu();

int main()
{
	//Declare Vehicles
	car mustang;
	truck ranger;
	plane cessna;
	boat catamaran;

	//Invalid Test Info
	//mustang.setAge(-1);
	//mustang.setPrice(-1);

	//Valid Info
	mustang.setAge(1985);
	mustang.setPrice(6000.00);
	mustang.setHeading("North");

	ranger.setAge(2001);
	ranger.setPrice(7256.40);
	ranger.setHeading("West");

	cessna.setAge(1990);
	cessna.setPrice(14000);
	cessna.setHeading("East");

	catamaran.setAge(2010);
	catamaran.setPrice(60000);
	catamaran.setHeading("South");

	//Declare and Open Log File
	std::ofstream log("log.txt");

	//Holder Variable
	char input;

	//Begin Log
	log << "Program Started" << std::endl;
	
	//VEHICLE MENU
	do
	{
		//Prompt
		vehicleMenu();
		std::cin >> input;
		input = toupper(input);

		switch (input)
		{
			//CAR
		case 'C':
			log << "Started Trip" << std::endl;
			mustang.start();
			log << "Car Started" << std::endl;
			std::cout << "Car Started" << std::endl;
			mustang.printCarOptions();
			do
			{
				std::cout << "Choice: ";
				std::cin >> input;
				input = toupper(input);
				switch (input)
				{
				case 'I':
					mustang.printCarInfo();
					log << "Car Info Requested" << std::endl;
					break;
				case 'O':
					mustang.printCarOptions();
					log << "Car Controls Requested" << std::endl;
					break;
				case 'R':
					mustang.toggleRadio();
					log << "Toggled Radio" << std::endl;
					break;
				case 'J':
					mustang.toggleSpoiler();
					log << "Toggled Spoiler / Race Mode" << std::endl;
					break;
				case 'U':
					mustang.toggleWindshieldWipers();
					log << "Toggled Wipers" << std::endl;
					break;
				case 'P':
					mustang.park();
					log << "Shifted Into Park" << std::endl;
					break;
				case 'D':
					mustang.drive();
					log << "Shifted Into Drive" << std::endl;
					break;
				case 'N':
					if (mustang.moveNorth())
					{
						log << "Drove North" << std::endl;
					}
					else
					{
						log << "Failed to Drive North" << std::endl;
					}
					break;
				case 'S':
					if (mustang.moveSouth())
					{
						log << "Drove South" << std::endl;
					}
					else
					{
						log << "Failed to Drive South" << std::endl;
					}
					break;
				case 'E':
					if (mustang.moveEast())
					{
						log << "Drove East" << std::endl;
					}
					else
					{
						log << "Failed to Drive East" << std::endl;
					}
					break;
				case 'W':
					if (mustang.moveWest())
					{
						log << "Drove West" << std::endl;
					}
					else
					{
						log << "Failed to Drive West" << std::endl;
					}
					break;
				case 'Q':
					if (mustang.getIsParked() == false)
					{
						std::cout << "Cannot Exit Moving Vehicle" << std::endl;
						log << "Attempted to Exit Moving Vehicle" << std::endl;
						input = 'Z';
					}
					break;
				default:
					break;
				}

			} while (input != 'Q');
			std::cout << "Turning Off Ignition" << std::endl;
			std::cout << "Exiting Car" << std::endl;
			mustang.turnOff();
			log << "Turned Off Ignition" << std::endl;
			log << "Exited Car" << std::endl;
			log << "Ended Trip" << std::endl;
			break;

			//TRUCK
		case 'T':
			log << "Started Trip" << std::endl;
			ranger.start();
			log << "Truck Started" << std::endl;
			std::cout << "Truck Started" << std::endl;
			ranger.printTruckOptions();
			do
			{
				std::cout << "Choice: ";
				std::cin >> input;
				input = toupper(input);
				switch (input)
				{
				case 'I':
					ranger.printTruckInfo();
					log << "Truck Info Requested" << std::endl;
					break;
				case 'O':
					ranger.printTruckOptions();
					log << "Truck Controls Requested" << std::endl;
					break;
				case 'U':
					ranger.toggleWindshieldWipers();
					log << "Toggled Windshield Wipers" << std::endl;
					break;
				case 'F':
					ranger.toggleFWD();
					log << "Toggled 4WD" << std::endl;
					break;
				case 'C':
					ranger.exchangeCornOil();
					log << "Attempted to Change Diesel Status" << std::endl;
					break;
				case 'P':
					ranger.park();
					log << "Shifted Into Park" << std::endl;
					break;
				case 'D':
					ranger.drive();
					log << "Shifted Into Drive" << std::endl;
					break;
				case 'N':
					if (ranger.moveNorth())
					{
						log << "Drove North" << std::endl;
					}
					else
					{
						log << "Failed to Drive North" << std::endl;
					}
					break;
				case 'S':
					if (ranger.moveSouth())
					{
						log << "Drove South" << std::endl;
					}
					else
					{
						log << "Failed to Drive South" << std::endl;
					}
					break;
				case 'E':
					if (ranger.moveEast())
					{
						log << "Drove East" << std::endl;
					}
					else
					{
						log << "Failed to Drive East" << std::endl;
					}
					break;
				case 'W':
					if (ranger.moveWest())
					{
						log << "Drove West" << std::endl;
					}
					else
					{
						log << "Failed to Drive West" << std::endl;
					}
					break;
				case 'Q':
					if (ranger.getIsParked() == false)
					{
						std::cout << "Cannot Exit Moving Vehicle" << std::endl;
						log << "Attempted to Exit Moving Vehicle" << std::endl;
						input = 'Z';
					}
					break;
				default:
					break;
				}

			} while (input != 'Q');
			std::cout << "Turning Off Ignition" << std::endl;
			std::cout << "Exiting Truck" << std::endl;
			ranger.turnOff();
			log << "Turned Off Ignition" << std::endl;
			log << "Exited Truck" << std::endl;
			log << "Ended Trip" << std::endl;
			break;

			//PLANE
		case 'P':
			log << "Started Trip" << std::endl;
			cessna.start();
			log << "Plane Started" << std::endl;
			std::cout << "Plane Started" << std::endl;
			cessna.printPlaneOptions();
			do
			{
				std::cout << "Choice: ";
				std::cin >> input;
				input = toupper(input);
				switch (input)
				{
				case 'I':
					cessna.printPlaneInfo();
					log << "Requested Plane Info" << std::endl;
					break;
				case 'O':
					cessna.printPlaneOptions();
					log << "Requested Plane Controls" << std::endl;
					break;
				case 'T':
					if (cessna.takeoff() == true)
					{
						log << "Took Off" << std::endl;
					}
					else
					{
						log << "Failed To Take Off" << std::endl;
					}
					break;
				case 'L':
					if (cessna.land() == true)
					{
						log << "Landed" << std::endl;
					}
					else
					{
						log << "Failed To Land" << std::endl;
					}
					break;
				case 'A':
					if (cessna.ascend() == true)
					{
						log << "Ascended" << std::endl;
					}
					else
					{
						log << "Failed to Ascend" << std::endl;
					}
					break;
				case 'D':
					if (cessna.descend() == true)
					{
						log << "Descended" << std::endl;
					}
					else
					{
						log << "Failed to Descend" << std::endl;
					}
					break;
				case 'N':
					if (cessna.moveNorth())
					{
						log << "Flew North" << std::endl;
					}
					else
					{
						log << "Failed to Fly North" << std::endl;
					}
					break;
				case 'S':
					if (cessna.moveSouth())
					{
						log << "Flew South" << std::endl;
					}
					else
					{
						log << "Failed to Fly South" << std::endl;
					}
					break;
				case 'E':
					if (cessna.moveEast())
					{
						log << "Flew East" << std::endl;
					}
					else
					{
						log << "Failed to Fly East" << std::endl;
					}
					break;
				case 'W':
					if (cessna.moveWest())
					{
						log << "Flew West" << std::endl;
					}
					else
					{
						log << "Failed to Fly West" << std::endl;
					}
					break;
				case 'Q':
					if (cessna.getLiftoffStatus())
					{
						std::cout << "Cannot Exit Moving Vehicle" << std::endl;
						log << "Attempted to Exit Moving Vehicle" << std::endl;
						input = 'Z';
					}
					break;
				default:
					break;
				}

			} while (input != 'Q');
			std::cout << "Turning Off Ignition" << std::endl;
			std::cout << "Exiting Plane" << std::endl;
			cessna.turnOff();
			log << "Turned Off Ignition" << std::endl;
			log << "Exited Plane" << std::endl;
			log << "Ended Trip" << std::endl;
			break;

			//BOAT
		case 'B':
			log << "Started Trip" << std::endl;
			catamaran.start();
			log << "Boat Started" << std::endl;
			std::cout << "Boat Started" << std::endl;
			catamaran.printBoatOptions();
			do
			{
				std::cout << "Choice: ";
				std::cin >> input;
				input = toupper(input);
				switch (input)
				{
				case 'I':
					catamaran.printBoatInfo();
					log << "Requested Boat Info" << std::endl;
					break;
				case 'O':
					catamaran.printBoatOptions();
					log << "Requested Boat Controls" << std::endl;
					break;
				case 'F':
					catamaran.toggleFlag();
					log << "Toggled Flag" << std::endl;
					break;
				case 'U':
					if (catamaran.undock())
					{
						log << "Un-Docked" << std::endl;
					}
					else
					{
						log << "Failed to Un-Dock" << std::endl;
					}
					break;
				case 'D':
					if (catamaran.dock())
					{
						log << "Docked" << std::endl;
					}
					else
					{
						log << "Failed to Dock" << std::endl;
					}
					break;
				case 'N':
					if (catamaran.moveNorth())
					{
						log << "Sailed North" << std::endl;
					}
					else
					{
						log << "Failed to Sail North" << std::endl;
					}
					break;
				case 'S':
					if (catamaran.moveSouth())
					{
						log << "Sailed South" << std::endl;
					}
					else
					{
						log << "Failed to Sail South" << std::endl;
					}
					break;
				case 'E':
					if (catamaran.moveEast())
					{
						log << "Sailed East" << std::endl;
					}
					else
					{
						log << "Failed to Sail East" << std::endl;
					}
					break;
				case 'W':
					if (catamaran.moveWest())
					{
						log << "Sailed West" << std::endl;
					}
					else
					{
						log << "Failed to Sail West" << std::endl;
					}
					break;
				case 'Q':
					if (catamaran.getIsDocked() == false)
					{
						std::cout << "Cannot Exit Un-Docked Vehicle" << std::endl;
						log << "Attempted to Exit Un-Docked Vehicle" << std::endl;
						input = 'Z';
					}
					break;
				default:
					break;
				}

			} while (input != 'Q');
			std::cout << "Turning Off Ignition" << std::endl;
			std::cout << "Exiting Boat" << std::endl;
			catamaran.turnOff();
			log << "Turned Off Ignition" << std::endl;
			log << "Exited Boat" << std::endl;
			log << "Ended Trip" << std::endl;
			break;
		case 'E':
			break;
		default:
			std::cout << "Invalid Option" << std::endl;
			log << "Attempted Entering Unknown Option" << std::endl;
			break;
		}
	} while (input != 'E');

	log << "Exiting Program" << std::endl;

	system("pause");
	return 0;
}

void vehicleMenu()
{
	std::cout << "" << std::endl;
	std::cout << "Please Select A Vehicle" << std::endl;
	std::cout << "----------------------- " << std::endl;
	std::cout << "C: Car   - Ford Mustang" << std::endl;
	std::cout << "T: Truck - Ford Ranger" << std::endl;
	std::cout << "P: Plane - Cessna 150" << std::endl;
	std::cout << "B: Boat  - Catamaran" << std::endl;
	std::cout << "E: Exit" << std::endl;
	std::cout << "Choice: ";
}