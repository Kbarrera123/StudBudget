# StudBudget

## What is StudBudget?

StudBudget is a student budgeting app that helps keep track of expenses and save money. StudBudget is a standalone C++ application with an integrated GUI built in Qt.

### Features

**1. Personalized financial advice**

* Based on our algorithms and your spending patterns!

**2. Data visualization**

* Pie charts and line graphs by month, year, and category!

**3. Specialized expense categories for college students**

* Includes:
  * Tuition
  * Food
  * Rent
  * Entertainment
  * Savings
  * Misc

**4. Your own StudBudget account and user profile!**

* Allows you to save your financial data
* Receive financial help tailored to you!

## Who created StudBudget?

StudBudget was created by a group of 7 UF Computer Science and Engineering students for a class project. For more information, see the _Authors_ section below.

#### Using StudBudget: A Note

To run a full version of StudBudget with GUI display on your computer, please contact one of the authors listed below for all the necessary files. This is because Qt is required to visualize the GUI. (More on this in _Deployment_)

## Getting Started

In order to build this app, we had a team of 7 that was split into several main areas (see _Authors_ below for who did what):

* Backend -- Calculations
* Frontend -- Qt GUI
* Data Visualization -- Using QtCharts
* Integration -- Combining the frontend and backend

### Prerequisites

Coding StudBudget required prior knowledge of C++, but some things we were able to learn along the way included:

* GitHub
* Qt
  * QtCreator
  * QtCharts
  * QtDesigner
* Databases (using a .txt file(s))
* User Authentication / Login system
* Encryption, Security, Hashing

### Installing

You will need to clone this GitHub repository (or make your own if you're starting from scratch), and download Qt.

We used the commercial trial of Qt, which only lasts for a short period of time, but you may be able to extend it if you contact the company. The Qt installation may take some time.

You can also use the open source version of Qt, which is free but does not include all the same features. Visit Qt's website for more details.

## Testing and Debugging

With so much code and so many different calculations and expense types, we ran into several bugs while using the app that were difficult to find in the code.

Be sure to use proper naming conventions and keep names consistent throughout the program!

It is important to check that each of the months and different features are working properly by inputing different data and catching edge cases.

## Deployment

Deployment was difficult using Qt. We were able to deploy the app for Windows by creating a standalone .exe file, but deploying for Mac proved to be more difficult.

It may be easier to start off using Qt Open Source, as it allows you to deploy the app more easily, it is free, and your access to it will not suddenly end like the commercial trial.

## Authors

For any questions or comments, please reach out to one of us!\*

* **Kayla Barrera** - _Qt GUI, GitHub Repo, Integration_ - [GitHub](https://github.com/Kbarrera123)
* **Luke Herczeg** - _Backend, Database, Integration, Deployment_ - [GitHub](https://github.com/lukeherczeg)
* **Caitlin Becker** - _Data Visualization in Qt_ - [GitHub](https://github.com/caitlinbecker)
* **Madeline Farina** - _Team Leader, Final Report, Security_ - [GitHub](https://github.com/mfarina1)
* **Christie Ruales** - _Qt GUI_ - [GitHub](https://github.com/cruales)
* **Justin Calloway** - _Product and Logo Design_ - [GitHub](https://github.com/jcallowayufl)
* **Cat Euliano** - [GitHub](https://github.com/ceuliano)

See also the list of [contributors](https://github.com/Kbarrera123/QtGUI2/graphs/contributors) who participated in this project.

\*Note: README created by Kayla Barrera (kaylabarrera@ufl.edu)
