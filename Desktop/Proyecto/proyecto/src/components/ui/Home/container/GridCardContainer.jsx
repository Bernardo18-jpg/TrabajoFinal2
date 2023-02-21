import React from "react";
import { Container } from "@nextui-org/react";
import CardEncuesta from "../card/CardEncuesta";

const GridCardContainer = () => {
  const cards = [
    {
      id: 1,
      titulo: "card 1",
      descripcion: "encuesta dsadas",
    },
    {
      id: 2,
      titulo: "card 2",
      descripcion: "encuesta dsadas",
    },
    {
      id: 3,
      titulo: "card 3",
      descripcion: "encuesta dsadas",
    },
    {
      id: 4,
      titulo: "card 4",
      descripcion: "encuesta dsadas",
    },
    {
      id: 1,
      titulo: "card 5",
      descripcion: "encuesta dsadas",
    },
  ];

  return (
    <Container>
      {cards.map((card) => (
        <CardEncuesta
          key={card.id}
          descripcion={card.descripcion}
          titulo={card.titulo}
          id={card.id}
        ></CardEncuesta>
      ))}
    </Container>
  );
};

export default GridCardContainer;
