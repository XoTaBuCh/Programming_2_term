#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

long double AreaOfCircle(long double r) {
    return PI * r * r;
}
long double AreaByAngle(long double r, long double a) {
    return r * r * a / 2;
}
long double Circumference(long double r) {
    return 2 * PI * r;
}
long double SideInscribedSquare(long double r) {
    return sqrt(2) * r;
}
long double VolumeOfCone(long double r) {
    return r * r * r * PI / 3;
}

int main(int argc, const char * argv[]) {
    int type;
    long double r = -1, a;
    while (1) {
        printf("Enter:\n");
        printf("1 - Entering the radius of a circle.\n");
        printf("2 - Outputting the area of a circle.\n");
        printf("3 - Outputting the area of the sector of the circle formed by the angle a.\n");
        printf("4 - Outputting the length of the corresponding circle.\n");
        printf("5 - Outputting the side of a square around which a circle is described.\n");
        printf("6 - Outputting the volume of a cone, the base of which is a circle, and the height of which is equal to the entered radius.\n");
        printf("7 - Information about the version and the author of the program.\n");
        printf("8 - Exiting the program.\n");
        scanf("%d", &type);
        switch (type){
            case 1:
                while(1) {
                    printf("Enter the radius >=0:\n");
                    scanf("%Lf", &r);
                    if (r >= 0) {
                        break;
                    }
                    else {
                        rewind(stdin);
                        continue;
                    }
                }
            case 2:
                if (r < 0) printf("Error, enter the radius >= 0!\n");
                else printf("Radius = %.2Lf, Area = %.2Lf\n", r, AreaOfCircle(r));
                break;
            case 3:
                if (r < 0) {
                    printf("Error, enter the radius >= 0!\n");
                    break;
                }
                while(1) {
                    printf("Enter the angle in radians (0 <= a <= 2 * PI): \n");
                    scanf("%Lf", &a);
                    if (a >= 0 && a <= 2 * PI) {
                       break;
                    }
                    else {
                        rewind(stdin);
                        continue;
                    }
                }
                printf("Radius = %.2Lf, Area = %.2Lf\n", r, AreaByAngle(r, a));
                break;
            case 4:
                if (r < 0) printf("Error, enter the radius >= 0!\n");
                else printf("Radius = %.2Lf, Circumference = %.2Lf\n", r, Circumference(r));
                break;
            case 5:
                if (r < 0) printf("Error, enter the radius >= 0!\n");
                else printf("Radius = %.2Lf, Side of the inscribed square = %.2Lf\n", r, SideInscribedSquare(r));
                break;
            case 6:
                if (r < 0) printf("Error, enter the radius >= 0!\n");
                else printf("Radius = %.2Lf, Volume of the cone = %.2Lf\n", r, VolumeOfCone(r));
                break;
            case 7:
                printf("Version 1.0, Author - XoT@B\n");
                break;
            case 8:
                return 0;
            default:
                rewind(stdin);
                printf("Error, enter 1-8!\n");
        }
    }
    return 0;
}