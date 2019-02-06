#ifndef SOURCE1_H_
#define SOURCE1_H_

/* Enum class to keep shapes */
enum class Shapes { rectangle, circle , triangle};

/* Function declared */
int rec_rec(double width, double height, double width2, double height2);
int rec_cir(double width, double height, double radius2);
int rec_tri(double width, double height, double edge2);

int cir_rec(double radius, double width2, double height2);
int cir_cir(double radius, double radius2);
int cir_tri(double radius, double edge2);

int tri_rec(double edge, double width2, double height2);
int tri_cir(double edge, double radius2);
int tri_tri(double edge, double edge2);

#endif
