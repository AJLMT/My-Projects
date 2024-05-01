-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 22-05-2023 a las 12:10:42
-- Versión del servidor: 10.4.28-MariaDB
-- Versión de PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `mi_tienda`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `contacto`
--

CREATE TABLE `contacto` (
  `codigo` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `telefono` char(9) NOT NULL,
  `descripcion` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalle`
--

CREATE TABLE `detalle` (
  `codigo_pedido` int(11) NOT NULL,
  `codigo_producto` int(11) NOT NULL,
  `unidades` int(11) DEFAULT NULL,
  `precio_unitario` decimal(8,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `detalle`
--

INSERT INTO `detalle` (`codigo_pedido`, `codigo_producto`, `unidades`, `precio_unitario`) VALUES
(12, 6, 1, 34.00),
(12, 8, 1, 39.99),
(13, 6, 1, 34.00),
(13, 8, 1, 39.99),
(14, 6, 1, 34.00),
(14, 8, 1, 39.99),
(15, 3, 1, 90.00),
(16, 3, 1, 90.00),
(17, 3, 1, 90.00),
(18, 3, 1, 90.00),
(19, 3, 2, 90.00),
(20, 3, 2, 90.00),
(21, 3, 2, 90.00),
(22, 3, 2, 90.00),
(27, 5, 1, 14.35),
(28, 5, 1, 14.35),
(29, 5, 3, 14.35),
(30, 5, 3, 14.35),
(31, 5, 3, 14.35),
(32, 5, 3, 14.35),
(33, 8, 1, 39.99),
(33, 9, 1, 6.79),
(34, 8, 1, 39.99),
(34, 9, 1, 6.79),
(35, 8, 1, 39.99),
(35, 9, 1, 6.79),
(36, 8, 1, 39.99),
(36, 9, 1, 6.79),
(37, 3, 1, 90.00),
(38, 3, 1, 90.00),
(39, 6, 1, 34.00),
(40, 16, 1, 6.49),
(41, 16, 1, 6.49),
(42, 16, 1, 6.49),
(43, 16, 1, 6.49),
(44, 16, 1, 6.49),
(45, 11, 1, 13.61),
(46, 10, 1, 12.79),
(47, 10, 1, 12.79),
(48, 10, 1, 12.79),
(49, 10, 1, 12.79),
(50, 3, 20, 4.50),
(51, 6, 1, 34.00),
(52, 6, 1, 34.00),
(60, 5, 1, 14.35),
(61, 5, 1, 14.35),
(62, 5, 1, 14.35),
(63, 5, 1, 14.35),
(64, 5, 1, 14.35),
(65, 5, 1, 14.35),
(66, 5, 1, 14.35),
(67, 5, 1, 14.35),
(68, 5, 1, 14.35),
(69, 5, 1, 14.35),
(70, 5, 1, 14.35),
(71, 5, 1, 14.35),
(72, 5, 1, 14.35),
(73, 5, 1, 14.35);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `estados`
--

CREATE TABLE `estados` (
  `codigo` int(11) NOT NULL,
  `descripcion` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `estados`
--

INSERT INTO `estados` (`codigo`, `descripcion`) VALUES
(1, 'Cancelado'),
(2, 'Comprado'),
(3, 'Tramitando');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pedidos`
--

CREATE TABLE `pedidos` (
  `codigo` int(11) NOT NULL,
  `persona` int(11) NOT NULL,
  `fecha` date DEFAULT NULL,
  `importe` decimal(8,2) DEFAULT NULL,
  `estado` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `pedidos`
--

INSERT INTO `pedidos` (`codigo`, `persona`, `fecha`, `importe`, `estado`) VALUES
(5, 10, '2023-05-08', 30.00, 1),
(6, 14, '2023-05-11', 30.00, 2),
(11, 1, '2023-05-11', 180.00, 1),
(12, 16, '2023-05-11', 88.00, 1),
(13, 16, '2023-05-11', 88.00, 3),
(14, 16, '2023-05-11', 88.00, 3),
(15, 16, '2023-05-11', 160.00, 3),
(16, 16, '2023-05-11', 160.00, 3),
(17, 16, '2023-05-11', 230.00, 3),
(18, 16, '2023-05-11', 230.00, 3),
(19, 16, '2023-05-11', 320.00, 3),
(20, 16, '2023-05-11', 320.00, 3),
(21, 16, '2023-05-11', 320.00, 3),
(22, 16, '2023-05-11', 320.00, 3),
(23, 16, '2023-05-11', 9.00, 3),
(24, 16, '2023-05-11', 9.00, 3),
(25, 16, '2023-05-11', 9.00, 3),
(26, 16, '2023-05-11', 9.00, 3),
(27, 16, '2023-05-11', 42.00, 3),
(28, 16, '2023-05-11', 42.00, 3),
(29, 16, '2023-05-11', 52.00, 3),
(30, 16, '2023-05-11', 52.00, 3),
(31, 16, '2023-05-11', 52.00, 3),
(32, 16, '2023-05-11', 52.00, 3),
(33, 16, '2023-05-11', 45.00, 3),
(34, 16, '2023-05-11', 45.00, 3),
(35, 16, '2023-05-11', 45.00, 3),
(36, 16, '2023-05-11', 45.00, 3),
(37, 16, '2023-05-11', 90.00, 3),
(38, 16, '2023-05-11', 90.00, 3),
(39, 16, '2023-05-11', 34.00, 3),
(40, 1, '2023-05-11', 6.00, 3),
(41, 1, '2023-05-11', 6.00, 3),
(42, 1, '2023-05-11', 6.00, 3),
(43, 1, '2023-05-11', 6.00, 3),
(44, 1, '2023-05-11', 6.00, 3),
(45, 1, '2023-05-11', 13.00, 3),
(46, 1, '2023-05-11', 82.00, 3),
(47, 1, '2023-05-11', 82.00, 3),
(48, 1, '2023-05-11', 12.00, 3),
(49, 1, '2023-05-11', 12.00, 3),
(50, 1, '2023-05-11', 2109.00, 3),
(51, 1, '2023-05-11', 53.00, 3),
(52, 1, '2023-05-11', 53.00, 3),
(53, 1, '2023-05-11', 79.00, 3),
(54, 1, '2023-05-11', 79.00, 3),
(55, 1, '2023-05-11', 70.00, 3),
(56, 1, '2023-05-11', 70.00, 3),
(57, 1, '2023-05-11', 70.00, 3),
(58, 1, '2023-05-11', 79.00, 3),
(59, 1, '2023-05-11', 79.00, 3),
(60, 1, '2023-05-11', 93.00, 3),
(61, 1, '2023-05-11', 93.00, 3),
(62, 1, '2023-05-11', 93.00, 3),
(63, 1, '2023-05-11', 93.00, 3),
(64, 1, '2023-05-11', 93.00, 3),
(65, 1, '2023-05-11', 93.00, 3),
(66, 1, '2023-05-11', 93.00, 3),
(67, 1, '2023-05-11', 93.00, 3),
(68, 1, '2023-05-11', 93.00, 3),
(69, 1, '2023-05-11', 93.00, 3),
(70, 1, '2023-05-11', 93.00, 3),
(71, 1, '2023-05-11', 93.00, 3),
(72, 1, '2023-05-11', 84.00, 3),
(73, 1, '2023-05-11', 84.00, 3),
(74, 1, '2023-05-11', 30.00, 3),
(75, 1, '2023-05-11', 30.00, 3),
(76, 1, '2023-05-11', 30.00, 3),
(77, 1, '2023-05-11', 100.00, 3),
(78, 1, '2023-05-11', 100.00, 3),
(79, 1, '2023-05-11', 100.00, 3),
(80, 1, '2023-05-11', 100.00, 3),
(81, 1, '2023-05-11', 100.00, 3),
(82, 1, '2023-05-11', 100.00, 3),
(83, 1, '2023-05-11', 100.00, 3),
(84, 1, '2023-05-11', 30.00, 3),
(85, 1, '2023-05-11', 30.00, 3),
(86, 1, '2023-05-11', 30.00, 3),
(88, 1, '2023-05-19', 9.00, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

CREATE TABLE `productos` (
  `codigo` int(11) NOT NULL,
  `descripcion` varchar(255) DEFAULT NULL,
  `precio` decimal(8,2) DEFAULT NULL,
  `existencias` int(11) DEFAULT NULL,
  `imagen` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `productos`
--

INSERT INTO `productos` (`codigo`, `descripcion`, `precio`, `existencias`, `imagen`) VALUES
(1, 'comida para perros', 65.00, 20, '../img/producto1.jpg'),
(2, 'lazo gatos', 65.00, 20, '../img/producto2.jpg'),
(3, 'Caseta para perros', 90.00, 24, '../img/producto3.jpg'),
(4, 'champú perros', 65.00, 20, '../img/producto4.jpg'),
(5, 'Quitapelos', 14.35, 20, '../img/producto5.jpg'),
(6, 'Transportin para gatos', 34.00, 20, '../img/producto6.jpg'),
(7, 'Rodillo mascotas', 7.89, 20, '../img/producto7.jpg'),
(8, 'Piscinita para perros', 39.99, 20, '../img/producto8.jpg'),
(9, 'Pelota goma indestructible', 6.79, 20, '../img/producto9.jpg'),
(10, 'KONG para perros', 12.79, 20, '../img/producto10.jpg'),
(11, 'Hueso juguete para perros', 13.61, 20, '../img/producto11.jpg'),
(12, 'Cama redonda mascotas', 18.65, 20, '../img/producto12.jpg'),
(13, 'Comedero PLUS', 93.49, 20, '../img/producto13.jpg'),
(14, 'Fuente para gatos', 49.90, 20, '../img/producto14.jpg'),
(15, 'Chuches para perros', 6.75, 20, '../img/producto15.jpg'),
(16, 'Collar parasitario para gatos', 6.49, 20, '../img/producto16.jpg');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `codigo` int(11) NOT NULL,
  `activo` int(11) DEFAULT NULL,
  `admin` int(11) DEFAULT NULL,
  `usuario` varchar(32) DEFAULT NULL,
  `clave` varchar(32) DEFAULT NULL,
  `nombre` varchar(64) DEFAULT NULL,
  `apellidos` varchar(128) DEFAULT NULL,
  `domicilio` varchar(128) DEFAULT NULL,
  `poblacion` varchar(64) DEFAULT NULL,
  `provincia` varchar(32) DEFAULT NULL,
  `cp` char(5) DEFAULT NULL,
  `telefono` char(9) DEFAULT NULL,
  `clave_cifrada` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`codigo`, `activo`, `admin`, `usuario`, `clave`, `nombre`, `apellidos`, `domicilio`, `poblacion`, `provincia`, `cp`, `telefono`, `clave_cifrada`) VALUES
(1, 1, 0, 'anto', 'ant', 'Antonio', 'José López', 'Avinguda de l\'Universitat', 'Valencia', 'Valencia', '46184', '671839022', NULL),
(9, 0, 0, 'ant', 'anto', 'Antionoi', 'Lopez', 'ETSE', 'Valencia', 'Valencia', '45632', '456321456', NULL),
(10, 1, 0, 'he', 'H', 'HOLA', 'HOLA', 'H', 'H', 'H', '56987', '45632158', NULL),
(12, 1, 0, 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', NULL),
(13, 1, 0, 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', NULL),
(14, 1, 0, 'Manolito', 'manolito', 'Manolo', 'Bermudez', 'Alcarava', 'Valencia', 'Valencia', '56987', '456987456', NULL),
(15, 1, 0, 'APRUEBAME', 'hola', 'Alberto', 'García', 'Valencia', 'Valencia', 'Valencia', '46529', '56874123', NULL),
(16, 1, 0, 'Mario', 'Hola', 'Mario', 'Lopez', 'estornell', 'Valencia', 'Valencia', '46184', '569874123', NULL),
(17, 1, 1, 'admin', 'admin', 'Padre', 'Mario', 'ETSE', 'Valencia', 'Valencia', '45698', '654789321', NULL);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `contacto`
--
ALTER TABLE `contacto`
  ADD PRIMARY KEY (`codigo`);

--
-- Indices de la tabla `detalle`
--
ALTER TABLE `detalle`
  ADD PRIMARY KEY (`codigo_pedido`,`codigo_producto`),
  ADD KEY `contiene` (`codigo_producto`);

--
-- Indices de la tabla `estados`
--
ALTER TABLE `estados`
  ADD PRIMARY KEY (`codigo`);

--
-- Indices de la tabla `pedidos`
--
ALTER TABLE `pedidos`
  ADD PRIMARY KEY (`codigo`),
  ADD KEY `pedidopor` (`persona`),
  ADD KEY `enestado` (`estado`);

--
-- Indices de la tabla `productos`
--
ALTER TABLE `productos`
  ADD PRIMARY KEY (`codigo`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`codigo`),
  ADD UNIQUE KEY `usuario` (`usuario`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `contacto`
--
ALTER TABLE `contacto`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `estados`
--
ALTER TABLE `estados`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `pedidos`
--
ALTER TABLE `pedidos`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=89;

--
-- AUTO_INCREMENT de la tabla `productos`
--
ALTER TABLE `productos`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `detalle`
--
ALTER TABLE `detalle`
  ADD CONSTRAINT `contiene` FOREIGN KEY (`codigo_producto`) REFERENCES `productos` (`codigo`),
  ADD CONSTRAINT `referentea` FOREIGN KEY (`codigo_pedido`) REFERENCES `pedidos` (`codigo`);

--
-- Filtros para la tabla `pedidos`
--
ALTER TABLE `pedidos`
  ADD CONSTRAINT `enestado` FOREIGN KEY (`estado`) REFERENCES `estados` (`codigo`),
  ADD CONSTRAINT `pedidopor` FOREIGN KEY (`persona`) REFERENCES `usuarios` (`codigo`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
