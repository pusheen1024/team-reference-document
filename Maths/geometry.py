from functools import total_ordering
from math import atan2, pi
EPS = 10 ** (-9)

@total_ordering
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
 
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
 
    def __lt__(self, other):
        return self.x < other.x or self.x == other.x and self.y < other.y
 
    def __repr__(self):
        return f'{self.x} {self.y}'
  
class Line:
    def __init__(self, a, b):
        self.a = a.y - b.y
        self.b = b.x - a.x
        self.c = -self.a * a.x - self.b * a.y
 
    def belongs(self, point):
        return abs(self.side(point)) < EPS
 
    def side(self, point):
        return point.x * self.a + point.y * self.b + self.c
 
    def dist(self, point):
        return abs(self.a * point.x + self.b * point.y + self.c) / ((self.a ** 2 + self.b ** 2) ** 0.5)
 
class LineCoeff(Line):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c        
        
@total_ordering
class Vector:
    def __init__(self, a, b):
        self.x = b.x - a.x
        self.y = b.y - a.y
        self.a = a
        self.b = b
 
    def __mul__(self, other):
        return self.x * other.y - self.y * other.x
 
    def __pow__(self, other):
        return self.x * other.x + self.y * other.y
 
    def __lt__(self, other):
        return self * other < 0
 
    def __eq__(self, other):
        return self * other == 0
 
    def __str__(self):
        return f'{self.x} {self.y}'
 
    def __repr__(self):
        return f'{self.x} {self.y}'
    
    def polar(self):
        ans = atan2(self.y, self.x)
        if ans < 0:
            ans += 2 * pi
        return ans
 
    def length(self):
        return (self.x ** 2 + self.y ** 2) ** 0.5
 
class Segment:
    def __init__(self, a, b):
        self.line = Line(a, b)
        self.a = a
        self.b = b
 
    def belongs(self, point):
        if not self.line.belongs(point):
            return False
        return (min(self.a.x, self.b.x) - EPS <= point.x <= max(self.a.x, self.b.x) + EPS and
                        min(self.a.y, self.b.y) - EPS <= point.y <= max(self.a.y, self.b.y) + EPS)
 
    def dist(self, point):
        if Vector(self.a, self.b) ** Vector(self.a, point) < 0:
            return dist(point, self.a)
        if Vector(self.b, self.a) ** Vector(self.b, point) < 0:
            return dist(point, self.b)
        return self.line.dist(point)
 
    def seg_dist(self, other):
        if (self.line.side(other.a) * self.line.side(other.b) < 0 and
                other.line.side(self.a) * other.line.side(self.b) < 0):
            return 0
        return min(self.dist(other.a), self.dist(other.b),
                             other.dist(self.a), other.dist(self.b))
    
    def intersects(self, line):
        point = intersects(self.line, line)
        if point and Vector(point, self.a) ** Vector(point, self.b) <= 0:
            return point
        return False
 
class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
 
    def __repr__(self):
        return f'{self.x} {self.y} {self.r}'
 
    def belongs(self, p):
        return (self.x - p.x) ** 2 + (self.y - p.y) ** 2 <= self.r ** 2 + EPS
 
    def inside(self, circle):
        return (self.x - circle.x) ** 2 + (self.y - circle.y) ** 2 <= (self.r - circle.r) ** 2 + EPS 
 
def det(a, b, c, d):
    return a * d - b * c
 
def intersects(line1, line2):
    D = det(line1.a, line1.b, line2.a, line2.b)
    if D == 0:
        return False
    D1 = det(line1.c, line1.b, line2.c, line2.b)
    D2 = det(line1.a, line1.c, line2.a, line2.c)
    return Point(-D1 / D, -D2 / D)
 
def dist(point1, point2):
    return ((point2.x - point1.x) ** 2 + (point2.y - point1.y) ** 2) ** 0.5
 
def cw(a, b, c):
    return Vector(b, a) * Vector(b, c) < 0
 
def ccw(a, b, c):
    return Vector(b, a) * Vector(b, c) > 0
 
def convex_hull(points):
    p = sorted(points)
    n = len(points)
    up = list()
    down = list()
    up.append(p[0])
    down.append(p[0])
    for i in range(1, n):
        if i == n - 1 or not cw(p[n - 1], p[0], p[i]):
            while len(up) >= 2 and not ccw(up[len(up) - 2], up[len(up) - 1], p[i]):
                up.pop()
            up.append(p[i])
        if i == n - 1 or cw(p[n - 1], p[0], p[i]):
            while len(down) >= 2 and not cw(down[len(down) - 2], down[len(down) - 1], p[i]):
                down.pop()
            down.append(p[i])
    return down + up[1:-1][::-1]
 
def intersects_c_l(circle, line, dx, dy):
    sq = line.a ** 2 + line.b ** 2
    if sq == 0:
        return []
    x0 = -line.a * line.c / sq
    y0 = -line.b * line.c / sq
    d0 = abs(line.c) / (sq ** 0.5)
    if d0 > circle.r + EPS:
        return []
    if d0 > circle.r - EPS:
        return [Point(x0 + dx, y0 + dy)]
    dsq = circle.r ** 2 - (line.c ** 2) / sq
    mult = (dsq / sq) ** 0.5
    P = Point(x0 + line.b * mult + dx, y0 - line.a * mult + dy)
    Q = Point(x0 - line.b * mult + dx, y0 + line.a * mult + dy)
    return [P, Q]
 
def intersects_c_c(circle1, circle2):
    circle2.x -= circle1.x
    circle2.y -= circle1.y
    line = LineCoeff(2 * circle2.x, 2 * circle2.y, circle2.r ** 2 - circle1.r ** 2 - circle2.x ** 2 - circle2.y ** 2)
    ans = intersects_c_l(Circle(0, 0, circle1.r), line, circle1.x, circle1.y)
    circle2.x += circle1.x
    circle2.y += circle1.y
    return ans
