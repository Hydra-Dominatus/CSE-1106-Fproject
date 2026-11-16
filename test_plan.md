Test Cases:

1. User input validation: Accepts only numerical input.
2. After filling up the room and changing maximum occupancy to a number lesser than initial occupancy, ensure that performing exit room updates the occupancy information to reflect new maximum occupancy.
3. Ensure that performing an entry or exit function creates a timestamp for the event in the change_log.txt file.
4. With the study room at maximum capacity, deny further entry into the room and display message of room being at max.
5. Ensure that the LED turns on when the room is at maximum capacity and turns off when a user leaves the room.
6. Ensure LED changes to reflect a change in the maximum occupancy. If old maximum occupancy is less than new maximum occupancy, LED stays on and if old maximum occupancy is less than new maximum occupancy, LED turns off.
7. Ensure that LED turns off when option 4, exit, is selected.

1. 2/5    SPACE AVAILABLE OFF
2. 4/5    SPACE AVAILABLE OFF
3. 5/5    ROOM FULL        ON
4. 0/5    SPACE AVAILABLE OFF
5. 6/5    ROOM FULL        ON
