# Clinic Management System

This project is a C-based Clinic Management System that enables easy patient record management and reservation tracking. The system operates in both admin and user modes, offering tailored functionalities to suit different user needs.

## Features

### Admin Mode

To access the admin mode, the user is prompted to enter a password. After 3 unsuccessful attempts, the system closes.

1. **Add New Patient Record:**
   The admin can enter patient information including name, age, gender, and a unique ID. The system rejects duplicate IDs.

2. **Edit Patient Record:**
   By entering a patient ID, the admin can modify patient information if the ID exists. Incorrect IDs prompt an error message.

3. **Reserve a Slot with the Doctor:**
   The admin can allocate one of the available time slots to a patient, preventing that slot from being booked again.

4. **Cancel Reservation:**
   Reservations can be canceled by entering the patient ID, making the slot available again.

### User Mode

1. **View Patient Record:**
   Users can view basic patient information by entering the patient ID.

2. **View Today's Reservations:**
   The system displays all reservations for the current day, including patient IDs associated with each slot.

## How to Use

1. Compile the provided C code using a C compiler (e.g., gcc).
2. Run the compiled executable in the terminal or command prompt.
3. Choose between admin and user modes based on your needs.

### Admin Mode

- Enter the default password (1234) or your custom password.
- Use the provided options to add, edit, reserve, or cancel patient reservations.

### User Mode

- Select user mode without a password.
- View patient records by entering the patient ID.
- Check today's reservations to see the scheduled slots and associated patient IDs.

## Note

This project offers a simplified implementation of a clinic management system. For a complete system, additional features and security measures may be required.

Feel free to explore and modify the code to match your specific requirements.

