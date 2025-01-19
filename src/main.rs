use camera::RustmonCamera;
use macroquad::prelude::*;
use macroquad::input;

use crate::renderer::Renderer; // Make sure this import is included

mod delta;
mod camera;
mod position;
mod renderer;

fn process_key_input(camera: &mut RustmonCamera) {
    if input::is_key_down(KeyCode::W) {
        camera.set_position(camera.get_x(), camera.get_y() - 0.5);
    }
    if input::is_key_down(KeyCode::S) {
        camera.set_position(camera.get_x(), camera.get_y() + 0.5);
    }
    if input::is_key_down(KeyCode::A) {
        camera.set_position(camera.get_x() - 0.5, camera.get_y());
    }
    if input::is_key_down(KeyCode::D) {
        camera.set_position(camera.get_x() + 0.5, camera.get_y());
    }
}

#[macroquad::main("RustmonRed")]
async fn main() {
    let mut camera =  camera::create();
    let mut delta = delta::create();
    let renderer = renderer::basic::create();

    delta.set_multiplier(1.0);
    loop {
        delta.update();
        renderer.render(&mut camera, &mut delta);
        process_key_input(&mut camera);        
        next_frame().await
    }
}
