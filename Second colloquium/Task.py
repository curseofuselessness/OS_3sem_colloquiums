from datetime import datetime

class Task:
    def __init__(self, title, year, month, day, description = ""):
        self.id = None # Номер
        self.title = title # Название
        self.description = description # Описание
        self.is_completed = False  # Статус выполнения
        self.__created_at = datetime.now()  # Дата создания (автоматически)
        self.__complete_to = datetime(year, month, day)  # Дедлайн
        self.completed_at = None  # Дата создания (автоматически)
    
    def complete(self):
        self.is_completed = True
        self.completed_at = datetime.now()