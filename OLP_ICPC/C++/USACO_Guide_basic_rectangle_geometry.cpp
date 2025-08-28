// calculate area
long long area(int bl_x, int bl_y, int tr_x, int tr_y) {
    long long length = tr_y - bl_y;
    long long width = tr_x - bl_x;
    return length * width;
}

// check if 2 rectangles intersect
bool intersect(vector<int> s1, vector<int> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];
	// no overlap
	if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y || tr_a_y <= bl_b_y) return false;
	else return true;
}

// calculate area of intersection
int intersection_area(vector<int> s1, vector<int> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];
	return ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) * (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)));
}