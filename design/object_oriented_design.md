# Object Oriented Design

## Step 1. Handle ambiguity
* who is going to use it.
* how they are going to use it.
* over all: who, what, where, when, how, why

## Step 2. Define your core objects
* e.g. restaurant: Table, Guest, Party, Order, Meal, Employee, Server, Host, etc

## Step 3. Analyze Relationships
* is-a, has-a, inherit, 1-m, m-n

## Step 4. Investigate Actions
* key actions the objects will take, how they are related to each other


# Case Study
1. Card Game
    * Deck of Cards: can shuffle and 
    * Card: can be inherited by poker, uno, etc
    * Suit: diamond and face val
    * Hand: used to get value and compare

1. Call Center
    * Employee
    * Call
    * Caller
    * Handler (assign call to employee and record the call info)

1. Jukebox
    * Jukebox 
    * CDPlayer (CD or Playlist)
    * CD (info)
    * Playlist (get next song to play, SongQueue)
    * Song (info)
    * User (info)

1. Parking Lot
    * s1: 
        * users: vehicles
        * public? free? time limit? for disability? 
    * s2:
        * ParkingLot
        * Level
        * ParkingSpot
        * Vehicle (different size, different price)
    * s3:
        * ParkingLot has several levels, each level has several ParkingSpots
        * Car, Bus, Bike are Vehicles
    * s4:
        * ParkingLot -> park an vehicle (find a suitable and available spot)
        * Level -> get available spots
        * ParkingSpot -> isAvailabe, getSize
        * Vehicle -> park, leave

1. Online Book Reader
    * s1: 
        * users: people 
        * free? search? read only by one user? one user one book? read permission
        * display
    * s2:
        * BookReaderSys
        * UserManager
        * User
        * Book
        * Library
        * Display
    * s3:
        * BookReaderSys has Library, Display, Books and Users
        * UserManager has users
        * Library has Books
        * VIP User and Normal User are Users
        * Display has Book and User
    * s4:
        * BookReaderSys -> get Active User and Book
        * UserManager -> add and delete User
        * Book has permission level -> canBeRead
        * User has level -> escalate, pay, removeMembership
        * Library -> addBook, removeBook, findBook
        * Display -> show Book and User 

1. Jigsaw
    * s2:
        * Jigsaw
        * Piece
        * Edge
    * s3:
        * Jigsaw has several Pieces
        * Piece has four edges
        * Edge has shape
    * s4: 
        * Jigsaw -> solve
        * Piece -> rotateEdge, isCorner, isBorder
        * Edge -> fitsWith

1. Chat Server
    * s1: 
        * can manage user
        * display chat history 
        * group chat
    * s2: 
        * Server
        * UserManager
        * User
        * Display
        * Message
        * AddRequest
        * Conversation
    * s3:
        * Server has UserManager
        * UserManager has several Users
        * User has Conversations, Users
        * Group has Users
        * Display has Users and Messages
        * Message has Users and Groups
    * s4:
        * Server -> use UserManager 
        * UserManager -> add / delete User, approve / reject AddRequest
        * User -> sendMessage to user / group, add / delete contact, send / remove Request, add / delete conversation
        * Conversation -> add / get Messages
        * Message -> infos
        * AddRequest -> from / to / date

1. File System
    * s1: 
        * in-memory
    * s2:
        * Entry -> File, Directory
    * s3:
    * s4: 
        * Entry -> delete, changeName
        * File -> getContents
        * Directory -> delete, add entry, getEntries

# More Cases
1. Chess
    * s1:
        * start game
        * make movement
        * different piece, different move
        * get winner
    * s2:
        * Game
        * Board
        * Piece
            * Elephant, Horse, King
    * s3:
        * Game has one Board
        * Board has several Pieces
    * s4:
        * Game -> start a new Board, announce the winner, track hist
        * Board -> movePiece, removePiece, checkMove
        * Piece -> nextMove(curPosition)

1. Elevator
    * s1: 
        * several elavators
        * go up / down
        * take specific weight people
        * status (door, direction, floor)
    * s2:
        * ElevatorManager
        * Elevator
        * Command
            * different commands (Emergency, Floor, Call, CloseDoor)
        * FloorIndicator
    * s3:
        * ElevatorManager has several Elevators
        * Elevator has several Commands (Command Pattern), has several FloorIndicator
        * Command is inherited by different command
    * s4:
        * ElevatorManager -> requestElevator (direction, floor)
        * Elevator -> curFloor, doorStatus, weightStatus, maxWeight, direction, commands[]
        * Command -> execute, undo 
        * FloorIndicator -> observor, when elevator floor change, update itself

1. Linux Find
    * s1: 
        * can find file with different condition
        * virtual file system to support find 
    * s2: 
        * Entry
            * File, Directory
        * Finder
        * FinderBehavior
            * FinderByPattern, FinderByFallFileName, FinderWithPerm, FinderByGroup
    * s3: 
        * Directory has several Entry
        * Finder has FinderBehavior
        * FinderBehavior in Directory
    * s4:
        * Finder -> find(FinderBehavior fb)
