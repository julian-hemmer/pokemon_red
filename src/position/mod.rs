pub struct Position {
    pub x: f32,
    pub y: f32,
}

impl Position {
    pub fn set(&mut self, new_x: f32, new_y: f32) {
        self.x = new_x;
        self.y = new_y;
    }
}