#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <vector>
class Piece {
  public:
    Piece(const Piece&) = delete;
    Piece& operator=(Piece const&);
	
/*Method to_char: returns the rapresentation of the piece
  * input: -
  * output: piece's char
*/
    virtual char to_char() = 0;

/*Method set_pos: sets a new position 
  * input: an array of shorts (the new position)
  * output: -
 */
    virtual void set_pos(std::vector<short>) = 0;

 /* Metodo get_allowed_moves: studies all the possible moves of the piece
   * input: -
   * output: matrix (Nx2) of shorts (all the possible moves of the piece)
*/
    virtual std::vector<std::vector<short>> get_allowed_moves() = 0;

/*Metodo get_position: return the current position of the piece
  * input: -
  * output: array of (2) shorts (current position of the piece)
*/
    virtual std::vector<short> get_position() = 0;
	
/*Method get_color: return the color
  *input: -
  *output: 0 if the piece is white, 1 if it is black
*/
    virtual int get_color() = 0;
	
/*Mehod is_first_move: for the piece within is important, return if this is the first move
 *input: -
 *output: true if this is the first move, false otherwise
*/ 
    virtual bool is_first_move() = 0;

  protected:
    std::vector<short> position;
    bool first_move = true;
    int value;
    char repr;
    int color;
    Piece(){};
};

#endif