# CSVO
Making CSGO but 2d

## Rules
- 5v5
- bomb defuse/plant
- win conditions
    - kill the other team
    - explode the bomb
    - defuse the bomb
    - defend for full time
- rounds are 1:55M
- defuse is instant
- single round game
- bullets kill anyone
- game can pause for input (not async)

## TODO
- map
    - map key
        - \#  can only go through in 1 direction (tunnel/bridge)
        - x is a wall
        - o cant walk, but can see/shoot through
        - blank space - open space
        - B is bomb spawn
        - C is ct spawn
        - T is t spawn
        - P is a bomb site
        - n random useless character?
        - \@ is player 
        - \* is bullet
        - \+ is CPU? 
      
    - data stuff
        - type of wall
        - spawns 
        - sites
        - bomb area
    - features
        - print map
        - update map
        
- player/bot entity
    - can move
    - can shoot
    - can die
    - can plant bomb
    - can pick up bomb
    - has a team
    - has a coordinate/direction
    
- team entity 
    - rotate or not defending plant/site
    - contains the players
    - check for win
    
- AI rules
    - viewfind to shoot (look up,left,right,down)
    - plant bomb
    - defuse bomb
    - pathfind to bomb
    - RNG to hunt/defend
    
- MISC
    - 10 tick delay to get bomb


- 'game engine'
    - WASD controls
    - q to quit
    - c is a debug refresh
    - space to shoot
    - i to idle