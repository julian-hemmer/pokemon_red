use macroquad::prelude::*;

use crate::position::*;

pub struct RustmonCamera {
    position: Position
}

pub fn create() -> RustmonCamera {
    RustmonCamera { 
        position: Position {
            x: 0.0, y: 0.0
        }
    }
}

impl RustmonCamera {
    pub fn convert_x_position(&mut self, x_position: f32) -> f32 {
        self.position.x + x_position
    }

    pub fn convert_y_position(&mut self, y_position: f32) -> f32 {
        self.position.y + y_position
    }

    pub fn draw_line_at(&mut self,
            start_x: f32, start_y: f32, 
            end_x: f32, end_y: f32,
            thickness: f32, color: Color) {
        draw_line(
            self.convert_x_position(start_x), 
            self.convert_y_position(start_y),
            self.convert_x_position(end_x), 
            self.convert_y_position(end_y),
                thickness, color);
    }
    
    pub fn set_position(&mut self, new_x: f32, new_y: f32) {
        self.position.set(new_x, new_y);
    }

    pub fn get_x(&self) -> f32 {
        self.position.x
    }

    pub fn get_y(&self) -> f32 {
        self.position.y
    }
}