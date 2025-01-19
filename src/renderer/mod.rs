use crate::camera::*;
use crate::delta::*;

pub mod basic;

pub trait Renderer {
    fn render(&self, camera: &mut RustmonCamera, delta: &mut Delta);
}
