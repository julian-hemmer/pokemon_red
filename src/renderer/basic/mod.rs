use macroquad::color;
use macroquad::time;

use crate::renderer::*;

pub struct BasicRenderer {
}

pub fn create() -> BasicRenderer {
    BasicRenderer {

    }
}

impl Renderer for BasicRenderer {
    fn render(&self, camera: &mut RustmonCamera, _: &mut Delta) {
        camera.draw_line_at(20.0, 20.0,
            50.0, 50.0, 10.0, color::RED);
        println!("FPS: {}", time::get_fps());
    }
}