Test Cases:

1. User input validation: Request for numerical input only when user enters a character or string
2. After filling up the room and changing maximum occupancy to a number lesser than initial occupancy, ensure that performing an exit updates the occupancy information to reflect new maximum occupancy.
3. Ensure that performing an entry or exit function creates a timestamp for the event in the change_log.txt file.
4. With the study room at maximum capacity, deny further entry into the room and display message of room being at max.
5. Ensure that the LED turns on when the room is at maximum capacity and turns off when a user leaves the room.
6. Ensure LED changes to reflect a change in the maximum occupancy. If old maximum occupancy is less than new maximum occupancy, LED stays on and if old maximum occupancy is less than new maximum occupancy, LED turns off.
