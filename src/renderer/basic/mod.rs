use macroquad::color;
use macroquad::time;
use macroquad::prelude::*;

use crate::renderer::*;

pub struct BasicRenderer {
}

pub fn create() -> BasicRenderer {
    BasicRenderer {

    }
}

impl Renderer for BasicRenderer {
    fn render(&self, camera: &mut RustmonCamera, delta: &mut Delta) {
        clear_background(BLACK);

        camera.draw_line_at(20.0, 20.0,
            50.0, 50.0, 10.0, color::RED);

            println!("FPS: {} | Delta: {}", time::get_fps(), delta.get());
        }
}