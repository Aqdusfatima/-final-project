#include <iostream>
#include <string>
using namespace std;
const int MAX_PATIENTS = 100;
const int MAX_DOCTORS = 50;
const int MAX_APPOINTMENTS = 200;
//structure for patient.
struct Patient
 {
    int id;
    string name;
    int age;
    string disease;
};
//structure for doctor.
struct Doctor
 {
    int id;
    string name;
    string specialization;
    double fee;
};
//structure for appointment.
struct Appointment
 {
    int id;
    int patientId;
    int doctorId;
    string date;
    string time;
};
//structure for bill.
struct Bill 
{
    int patientId;
    double totalAmount;
};
//function for menu
void displayMenu()
 {
   cout<<   "                             ^^  ________________________________________ ^^\n";
 	cout<<  "                                   --------------------------------------\n";
    cout << "                                           Hospital Management System\n";
    cout<<  "                                   --------------------------------------\n";
    cout<<  "                              ^^   ________________________________________ ^^\n";
    cout<<  "\n";
    cin.get();
	system("cls");
    cout<<  "\t\t\t                    ^FOR PATIENT^\n   ";
    cout<<  " \n ";
    cout << "\t\t\t              1.  Add Patient Record\n";
    cout << "\t\t\t              2.  View All Patient Records\n";
    cout << "\t\t\t              3.  Update Patient Record\n";
    cout << "\t\t\t              4.  Delete Patient Record\n";
    cout<<  "\t\t\t              5.  Search Patient\n";
    cout<<  "\n";
    cout<<  "\t\t\t                    ^FOR DOCTOR^\n     ";
    cout<<  "\n";
    cout << "\t\t\t              6.  Add Doctor Record\n";
    cout << "\t\t\t              7.  View All Doctor Records\n";
    cout << "\t\t\t              8.  Update Doctor Record\n";
    cout << "\t\t\t              9.  Delete Doctor Record\n";
    cout<<  "\t\t\t              10. Search Doctor\n";
    cout<<  "\n";
    cout<<  "\t\t\t                   ^FOR APPOINTMENT^\n  ";
    cout<<  "\n";
    cout << "\t\t\t              11. Schedule Appointment\n";
    cout << "\t\t\t              12. View All Appointments\n";
    cout << "\t\t\t              13. Update Appointment\n";
    cout << "\t\t\t              14. Delete Appointment\n";
    cout<<  "\t\t\t              15. Search Appointment\n";
    cout<<  "\n";
    cout<<  "\t\t\t                  ^TO GENERATE BILL^\n   ";
    cout<<  "\n";
    cout << "\t\t\t              16. Generate Bill\n";
    cout<<  "\n";
    cout << "\t\t\t              17. Exit\n";
    cout<<  "  \n";
    cout << "   \t\t\t\t\t             Enter your choice:\n ";
    cout<<  "\n";
}
//function to add patient 
void addPatient(Patient patients[], int& patientCount)
 {
  if (patientCount >= MAX_PATIENTS) 
 {
  cout<<"--------------------------------------------------\n";
  cout << "Cannot add more patients. Maximum limit reached.\n";
  cout<<"-----------------------------------------------------\n";
 return; 
 }
 system("color 50");
  Patient newPatient;
   newPatient.id = patientCount + 1;
    // Auto generate ID 
	cout << "Enter Patient Name: ";
	 cin.ignore(); 
	 getline(cin, newPatient.name);
	  cout << "Enter Patient Age: ";
	   cin >> newPatient.age; 
	   cout << "Enter Patient Disease: "; 
	   cin.ignore();
	    getline(cin,newPatient.disease); 
		 patients[patientCount++] = newPatient; 
		 cout<<"----------------------------------------------------------------------\n";
		 cout << "Patient record added successfully with ID: " << newPatient.id << "\n";
		 cout<<"-----------------------------------------------------------------------\n";
		  }
//function for viewing patient record.
void viewPatients(const Patient patients[], int patientCount)
 {
 	system("color 70");
    if (patientCount == 0)
	 {
	 	cout<<"----------------------------\n";
        cout << "No patient records found.\n";
        cout<<"----------------------------\n";
        return;
     }
    for (int i = 0; i < patientCount; ++i)
	 {
	cout<<"________________________________________________________________________________\n";
    cout << "ID: " << patients[i].id << "\nName: " << patients[i].name
             <<"\nAge: " << patients[i].age << "\nDisease: " << patients[i].disease << endl;
    cout<<"________________________________________________________________________________\n";     
    }
}
//function for updating patient record.
void updatePatient(Patient patients[], int patientCount)
 {
    system("color ae");
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;
    for (int i = 0; i < patientCount; ++i)
	 {
        if (patients[i].id == id)
		 {
            cout << "Enter new Patient Name: ";
            cin.ignore();
            getline(cin, patients[i].name);
            cout << "Enter new Patient Age: ";
            cin >> patients[i].age;
            cout << "Enter new Patient Disease: ";
            cin.ignore();
            getline(cin, patients[i].disease);
            cout<<"-------------------------------------- \n";
            cout << "Patient record updated successfully. \n";
            cout<<"----------------------------------------\n";
            return;
        }
    }
    cout<<"----------------------------\n";
    cout << "Patient record not found.\n";
    cout<<"----------------------------\n";
}
//function for deleting patient record.
void deletePatient(Patient patients[], int& patientCount) 
{
	system("color 90");
    int id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;
    for (int i = 0; i < patientCount; ++i)
	 {
        if (patients[i].id == id)
		 {
            for (int j = i; j < patientCount - 1; ++j)
			 {
                patients[j] = patients[j + 1];
            }
            --patientCount;
            cout<<"---------------------------------------\n";
            cout << "Patient record deleted successfully.\n";
            cout<<"---------------------------------------\n";
            return;
        }
    }
    cout<<"-----------------------------\n";
    cout << "Patient record not found.\n";
    cout<<"-----------------------------\n";
}
//function to search patient record.
void searchPatient(const Patient patients[], int patientCount) 
{ 
system ("color f4");
int id;
 cout << "Enter Patient ID to search: \n";
  cin >> id; 
  for (int i = 0; i < patientCount; ++i)
   {
    if (patients[i].id == id)
	 { 
	 cout << "Patient found:\n"; 
	 cout<<"--------------------------------------------------------------------\n";
	 cout << "ID: " << patients[i].id << ", Name: " << patients[i].name << ", Age: " 
	 << patients[i].age << ", Disease: " << patients[i].disease << endl;
	 cout<<"--------------------------------------------------------------------\n";
	  return; 
	  } 
	  } 
	  cout<<"---------------------\n";
	  cout << "Patient not found.\n"; 
	  cout<<"---------------------\n";
	  }
//function for adding doctor.
void addDoctor(Doctor doctors[], int& doctorCount) 
{
	system("color 80");
 if (doctorCount >= MAX_DOCTORS)
 {
 	cout<<"-------------------------------------------------\n";
    cout << "Cannot add more doctors. Maximum limit reached.\n";
    cout<<"---------------------------------------------------\n";
   return;
    }
   Doctor newDoctor;
    newDoctor.id = doctorCount + 1;
	 // Auto-generate ID 
	cout << "Enter Doctor Name: ";
	 cin.ignore(); 
	 getline(cin, newDoctor.name); 
	 cout << "Enter Doctor Specialization: ";
	  getline(cin, newDoctor.specialization);
	   cout << "Enter Doctor Fee: "; 
	   cin >> newDoctor.fee;
	    doctors[doctorCount++] = newDoctor; 
	    cout<<"-----------------------------------------------------------------------\n";
		cout << "Doctor record added successfully with ID: " << newDoctor.id << "\n";
		cout<<"------------------------------------------------------------------------\n";
		 }
//function for viewing doctor record.
void viewDoctors(const Doctor doctors[], int doctorCount)
 {
 	system("color eC");
    if (doctorCount == 0) 
	{
		cout<<"---------------------------\n";
        cout << "No doctor records found.\n";
        cout<<"---------------------------\n";
        return;
    }
    for (int i = 0; i < doctorCount; ++i) 
	{
	    cout<<"------------------------------------------------\n";
    cout << "ID: " << doctors[i].id << "\nName: " << doctors[i].name<< "\nSpecialization: " 
    << doctors[i].specialization << "\nFee: " << doctors[i].fee << endl;
        cout<<"------------------------------------------------\n";
    }
}
//function for updating doctor record.
void updateDoctor(Doctor doctors[], int doctorCount) 
{
	system("color 60");
	int id;
    cout << "Enter Doctor ID to update: ";
    cin>>id;
    for (int i = 0; i < doctorCount; ++i)
	 {
        if (doctors[i].id == id)
		 {
            cout << "Enter new Doctor Name: ";
            cin.ignore();
            getline(cin, doctors[i].name);
            cout << "Enter new Doctor Specialization: ";
            getline(cin, doctors[i].specialization);
            cout << "Enter new Doctor Fee: ";
            cin >> doctors[i].fee;
            cout<<"--------------------------------------\n";
            cout << "Doctor record updated successfully.\n";
            cout<<"--------------------------------------\n";
            return;
        }
    }
    cout<<"--------------------------\n";
    cout << "Doctor record not found.\n";
    cout<<"-------------------------\n";
}
//function for deleting doctor record.
void deleteDoctor(Doctor doctors[], int& doctorCount) 
{
	system("color 10");
    int id;
    cout << "Enter Doctor ID to delete: ";
    cin >> id;
    for (int i = 0; i < doctorCount; ++i)
	 {
        if (doctors[i].id == id)
		 {
            for (int j = i; j < doctorCount - 1; ++j) 
			{
                doctors[j] = doctors[j + 1];
            }
            --doctorCount;
            cout<<"--------------------------------------\n";
            cout << "Doctor record deleted successfully.\n";
            cout<<"--------------------------------------/n";
            return;
        }
    }
    cout<<"---------------------------\n";
    cout << "Doctor record not found.\n";
    cout<<"---------------------------\n";
}
//function to search doctor record.
void searchDoctor(const Doctor doctors[], int doctorCount)
 {
 	system("color E2");
  int id;
   cout << "Enter Doctor ID to search: \n";
    cin >> id;
	 for (int i = 0; i < doctorCount; ++i) 
	 { 
	 if (doctors[i].id == id)
	 {
	 cout << "Doctor found:\n"; 
	 cout<<"--------------------------------------------------------------------\n";
	 cout << "ID: " << doctors[i].id << ", Name: " << doctors[i].name << ", Specialization: "
	 << doctors[i].specialization << ", Fee: " << doctors[i].fee << endl;
	 cout<<"--------------------------------------------------------------------\n";
	  return; 
	  }
	  }
	  cout<<"-------------------\n";
	  cout << "Doctor not found.\n";
	  cout<<"-------------------\n";
	  }
//function for scheduling appointment.
void scheduleAppointment(Appointment appointments[], int& appointmentCount, const Patient patients[], int patientCount, const Doctor doctors[], int doctorCount)
 { 
 system("color eB");
 if (appointmentCount >= MAX_APPOINTMENTS) 
 { 
 cout<<"------------------------------------------------------------\n";
 cout << "Cannot schedule more appointments. Maximum limit reached.\n";
 cout<<"------------------------------------------------------------\n";
  return;
 } 
   int patientId;
   int doctorId;
    Appointment newAppointment;
     // Auto generate ID 
    newAppointment.id = appointmentCount + 1;
    cout << "Enter Patient ID: ";
    cin >> patientId;
    cout << "Enter Doctor ID: ";
    cin >> doctorId;
    // Validate Patient ID
	 bool patientFound = false;
     for (int i = 0; i < patientCount; ++i)
	 { 
	 if (patients[i].id == patientId)
	 { 
	patientFound = true; 
	newAppointment.patientId = patientId;
    break;
    }
    }
    if (!patientFound)
    { 
    cout<<"---------------------------------------------------------\n";
    cout << "Patient ID not found. Please enter a valid Patient ID.\n";
    cout<<"----------------------------------------------------------\n";
    return; 
    } 
    // Validate Doctor ID
    bool doctorFound = false;
   for (int i = 0; i < doctorCount; ++i) 
   { 
   if (doctors[i].id == doctorId) 
   {
    doctorFound = true;
    newAppointment.doctorId = doctorId; 
	break; 
	} 
	} 
	if (!doctorFound) 
    { cout << "Doctor ID not found. Please enter a valid Doctor ID.\n";
    return;
	 } 
    cout << "Enter Appointment Date (YYYY-MM-DD): "; 
    cin.ignore(); 
	getline(cin, newAppointment.date); 
   cout << "Enter Appointment Time (HH:MM): "; 
   getline(cin, newAppointment.time);
   appointments[appointmentCount++] = newAppointment;
   cout<<"--------------------------------------------------------------------------\n";
   cout << "Appointment scheduled successfully with ID: " << newAppointment.id << "\n";
   cout<<"---------------------------------------------------------------------------\n";
    }
//function for viewing appointment.
void viewAppointments(const Appointment appointments[], int appointmentCount)
 {
 system("color DB");
    if (appointmentCount == 0)
	 {
	 	cout<<"-------------------------\n";
        cout << "No appointments found.\n";
        cout<<"-------------------------\n";
        return;
    }
    for (int i = 0; i < appointmentCount; ++i) 
	{
   cout<<"------------------------------------------------\n";
   cout << "ID: " << appointments[i].id << "\nPatient ID: " << appointments[i].patientId
   << "\nDoctor ID: " << appointments[i].doctorId << "\nDate: " << appointments[i].date
   << "\nTime: " << appointments[i].time << endl;
   cout<<"------------------------------------------------\n";
    }
}
//function for updating appointment.

void updateAppointment(Appointment appointments[], int appointmentCount)
 {
 	system("color CE");
    int id;
    cout << "Enter Appointment ID to update: ";
    cin >> id;
    for (int i = 0; i < appointmentCount; ++i)
	 {
        if (appointments[i].id == id) 
		{
            cout << "Enter new Patient ID: ";
            cin >> appointments[i].patientId;
            cout << "Enter new Doctor ID: ";
            cin >> appointments[i].doctorId;
            cout << "Enter new Appointment Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, appointments[i].date);
            cout << "Enter new Appointment Time (HH:MM): ";
            getline(cin, appointments[i].time);
            cout<<"---------------------------------------------\n";
            cout << "Appointment record updated successfully.\n";
            cout<<"---------------------------------------------\n";
            return;
        }
    }
    cout<<"--------------------------------\n";
    cout << "Appointment record not found.\n";
    cout<<"--------------------------------\n";
}
//function for deleting appointment.
void deleteAppointment(Appointment appointments[], int& appointmentCount) 
{
	system("color bd");
    int id;
    cout << "Enter Appointment ID to delete: ";
    cin >> id;
    for (int i = 0; i < appointmentCount; ++i)
	 {
        if (appointments[i].id == id)
		 {
            for (int j = i; j < appointmentCount - 1; ++j)
			 {
                appointments[j] = appointments[j + 1];
            }
            --appointmentCount;
            cout<<"-------------------------------------------\n";
            cout << "Appointment record deleted successfully.\n";
            cout<<"-------------------------------------------\n";
            return;
        }
    }
    cout<<"--------------------------------\n";
    cout << "Appointment record not found.\n";
    cout<<"--------------------------------\n";
}
//function to serach appointment record.
void searchAppointment(const Appointment appointments[], int appointmentCount) 
{ 
system ("color B2");
int id;
 cout << "Enter Appointment ID to search:\n "; 
 cin >> id; 
 for (int i = 0; i < appointmentCount; ++i) 
 { 
 if (appointments[i].id == id)
  {
   cout << "Appointment found:\n";
   cout<<"---------------------------------------------------------------------------------\n";
   cout << "ID: " << appointments[i].id << ", Patient ID: " << appointments[i].patientId << ", Doctor ID: " 
   << appointments[i].doctorId << ", Date: " << appointments[i].date << ", Time: "<< appointments[i].time<< endl;
   cout<<"---------------------------------------------------------------------------------\n";
   return; 
  }
  }
  cout<<"--------------------------\n";
  cout << "Appointment not found.\n";
  cout<<"-------------------------\n";
   }
//function for generating bill.
void generateBill(const Patient patients[], int patientCount, const Doctor doctors[], int doctorCount, const Appointment appointments[], int appointmentCount) 
{
    system("color eC");
	int patientId;
    cout << "Enter Patient ID to generate bill: ";
    cin >> patientId;
    double totalAmount = 0;
    for (int i = 0; i < appointmentCount; ++i)
	 {
        if (appointments[i].patientId == patientId) 
		{
            for (int j = 0; j < doctorCount; ++j) 
			{
                if (doctors[j].id == appointments[i].doctorId)
				 {
                    totalAmount += doctors[j].fee;
                }
            }
        }
    }
    cout<<"-------------------------------------------------------------------------\n";
    cout << "Total Bill for Patient ID " << patientId << ": " << totalAmount << endl;
    cout<<"--------------------------------------------------------------------------\n";
}
//main function.
int main()
 {
    system("color Ec");
    system("color 10");
    system("color 20");
    system("color 30");
    system("color 40");
    system("color 50");
    system("color Df");
    system("color cC");
    system("color 60");
    system("color 70");
    system("color 80");
    system("color eb");
    system("color dE");
    system("color cA");
 	system("color FB");
    Patient patients[MAX_PATIENTS];
    Doctor doctors[MAX_DOCTORS];
    Appointment appointments[MAX_APPOINTMENTS];
    int patientCount = 0, doctorCount = 0, appointmentCount = 0;
    int choice;
    do 
	{
      displayMenu();
      cin >> choice;
       switch (choice)
		 {
            case 1:
                addPatient(patients, patientCount);
                break;
            case 2:
                viewPatients(patients, patientCount);
                break;
            case 3:
                updatePatient(patients, patientCount);
                break;
            case 4:
                deletePatient(patients, patientCount);
                break;
            case 5:
			    searchPatient(patients,patientCount);
			    break;
            case 6:
                addDoctor(doctors, doctorCount);
                break;
            case 7:
                viewDoctors(doctors, doctorCount);
                break;
            case 8:
                updateDoctor(doctors, doctorCount);
                break;
            case 9:
                deleteDoctor(doctors, doctorCount);
                break;
            case 10:
            	searchDoctor(doctors,doctorCount);
            	break;
            case 11:
                scheduleAppointment(appointments, appointmentCount, patients, patientCount, doctors, doctorCount);
                break;
            case 12:
                viewAppointments(appointments, appointmentCount);
                break;
            case 13:
                updateAppointment(appointments, appointmentCount);
                break;
            case 14:
                deleteAppointment(appointments, appointmentCount);
                break;
            case 15:searchAppointment(appointments,appointmentCount);
                break;
            case 16:
                generateBill(patients, patientCount, doctors, doctorCount, appointments, appointmentCount);
                break;
            case 17:
                cout << "Exiting program.\n";
                break;
            default:
            	cout<<"------------------------------------\n";
                cout << "Invalid choice. Please try again.\n";
                cout<<"------------------------------------\n";
        }
    } 
	while (choice != 17);
    return 0;
}																			    
