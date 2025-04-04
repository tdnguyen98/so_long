# 🧙‍♂️ so_long
so_long is a mandatory project from 42 School written in C using the MiniLibX graphics library. It's a simple yet charming 2D top-down game, where your goal is to collect all collectibles and then find the exit to complete the level.

![me](https://github.com/tdnguyen98/so_long/blob/main/So_long.gif)
Use your skills wisely, gather all the scrolls, and reach the exit safely.

## 🕹️ Controls
Key	Action
W	Move Up
S	Move Down
A	Move Left
D	Move Right
1	Use Spell 1 (if scroll & staff)
2	Use Spell 2 (if scroll & staff)
| Key / Input    | Action                       |
|----------------|------------------------------|
|   **`W`**	 | Move Up        |
|      **`S`**	 | Move Down         |
|   **`A`**	 | Move Left     |
|      **`D`**	 | Move Right      |
| **`1`**  / **`2`** | Use Spells (if scroll & staff)    |
| **`ESC`** | Leave Game               |

## ⚙️ Installation

To play the game, follow these steps:

### 1. Clone the repository
```bash
git clone https://github.com/your-username/so_long.git
```

### 2. Navigate into the project directory
```bash
cd so_long
```

### 3. Compile the game
```
make
````

### 4. Run the game with a valid map
```bash
./so_long path_to_map.ber
```

Feel free to test the default map `maps/map.ber

## Map Format
The map is a text file with .ber extension containing a rectangular grid with specific characters:

| Symbol    | Meaning                      |
|-----------|------------------------------|
| **`1`**	| Wall |
| **`0`**	| Walkable Path|
| **`P`**	| Player Start|
| **`C`**	| Collectible|
| **`E`**	| Exit|

Example:
```
111111
1P0C01
1000E1
111111
```

## Map Rules
- Must not be a square (width ≠ height).
- Must be enclosed by walls (1 on all edges).
- Must contain exactly one P (player) and one E (exit).
- Must have at least one C (collectible).
- All elements (collectibles and exit) must be reachable.
- Map extension must be `.ber`

## Compatibility
- ✅ MacOS
- ⚠️ Linux (Partially supported, but big issues exist)
	- MiniLibX has transparency issues on Linux, affecting image rendering.
	- The game remains playable, but it is visually uncomfortable due to graphical limitations and appears to have frame rate issues.
- Windows is not supported
